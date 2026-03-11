import React, { useEffect, useMemo, useState } from "react";
import TopBar from "../components/TopBar.jsx";
import SideNav from "../components/SideNav.jsx";
import { currentUser, mockSuppliers, mockSupplierTx } from "../data/mock.js";
import {
  SupplierHistoryModal,
  SupplierUpsertModal,
} from "../components/SupplierModals.jsx";
import { ConfirmDeleteDialog } from "../components/UserModals.jsx";

const STORAGE_KEY = "nutmilk_suppliers_v1";

function formatVND(n) {
  const s = String(Math.round(Number(n) || 0));
  return s.replace(/\B(?=(\d{3})+(?!\d))/g, ".") + " đ";
}

export default function Suppliers() {
  const [suppliers, setSuppliers] = useState(() => {
    const raw = localStorage.getItem(STORAGE_KEY);
    if (raw) {
      try {
        return JSON.parse(raw);
      } catch {
        return mockSuppliers;
      }
    }
    return mockSuppliers;
  });

  useEffect(() => {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(suppliers));
  }, [suppliers]);

  const [q, setQ] = useState("");
  const [statusFilter, setStatusFilter] = useState("Tất cả trạng thái");

  const [openAdd, setOpenAdd] = useState(false);
  const [openEdit, setOpenEdit] = useState(false);
  const [editing, setEditing] = useState(null);

  const [openHistory, setOpenHistory] = useState(false);
  const [historySupplier, setHistorySupplier] = useState(null);

  const [openDel, setOpenDel] = useState(false);
  const [deleting, setDeleting] = useState(null);

  const filtered = useMemo(() => {
    const s = q.trim().toLowerCase();
    let list = suppliers;

    if (statusFilter !== "Tất cả trạng thái") {
      list = list.filter((x) => x.status === statusFilter);
    }

    if (!s) return list;
    return list.filter((x) => {
      const blob = [
        x.code,
        x.name,
        x.address,
        x.phone,
        x.email,
        x.taxId,
        x.status,
      ]
        .join(" ")
        .toLowerCase();
      return blob.includes(s);
    });
  }, [suppliers, q, statusFilter]);

  const onCreate = (payload) => {
    // auto code: NCC + chạy số nếu bạn không nhập code (đúng ảnh: NCC01..)
    const maxNo = suppliers
      .map((s) => s.code)
      .filter((c) => /^NCC\d+$/i.test(c))
      .map((c) => parseInt(c.replace(/[^\d]/g, ""), 10))
      .reduce((a, b) => Math.max(a, b), 0);

    const code = payload.code?.trim() || `NCC${String(maxNo + 1).padStart(2, "0")}`;

    if (suppliers.some((x) => x.code === code)) {
      alert("Mã NCC đã tồn tại.");
      return;
    }

    setSuppliers((prev) => [
      {
        code,
        name: payload.name,
        address: payload.address,
        phone: payload.phone,
        email: payload.email,
        taxId: payload.taxId,
        note: payload.note || "",
        status: payload.status || "Đang hợp tác",
        totalValue: 0,
      },
      ...prev,
    ]);
  };

  const onEdit = (payload) => {
    setSuppliers((prev) =>
      prev.map((x) => (x.code === payload.code ? { ...x, ...payload } : x))
    );
  };

  const onDelete = () => {
    if (!deleting) return;
    setSuppliers((prev) => prev.filter((x) => x.code !== deleting.code));
    setDeleting(null);
    setOpenDel(false);
  };

  return (
    <div>
      <TopBar user={currentUser} bellCount={0} />

      <div className="supWrap">
        <SideNav />

        <div className="supPanel">
          <div className="supPanelTitleRow">
            <div className="supPanelTitle">Quản lý nhà cung cấp</div>
          </div>

          <div className="supPanelBody">
            <div className="supFilters">
              <div className="supSearch">
                <span className="supSearchIcon">🔍</span>
                <input
                  value={q}
                  onChange={(e) => setQ(e.target.value)}
                  placeholder="Tìm kiếm..."
                />
              </div>

              <select
                className="supSelect"
                value={statusFilter}
                onChange={(e) => setStatusFilter(e.target.value)}
              >
                <option>Tất cả trạng thái</option>
                <option>Đang hợp tác</option>
                <option>Ngừng hợp tác</option>
              </select>

              <button className="supAddBtn" onClick={() => setOpenAdd(true)}>
                + Thêm nhà cung cấp
              </button>
            </div>

            <div className="supTableOuter">
              <table className="supTable">
                <thead>
                  <tr>
                    <th style={{ width: 100 }}>Mã NCC</th>
                    <th style={{ width: 260 }}>Tên nhà cung cấp</th>
                    <th style={{ width: 210 }}>Liên hệ</th>
                    <th style={{ width: 150 }}>Mã số thuế</th>
                    <th style={{ width: 170 }}>Tổng giá trị GD</th>
                    <th style={{ width: 140 }}>Trạng thái</th>
                    <th style={{ width: 110, textAlign: "center" }}>Thao tác</th>
                  </tr>
                </thead>
                <tbody>
                  {filtered.map((s) => (
                    <tr key={s.code}>
                      <td className="supTdCode">{s.code}</td>

                      <td>
                        <div className="supName">{s.name}</div>
                        <div className="supSub">
                          <span className="supSubIcon">📍</span>
                          {s.address}
                        </div>
                      </td>

                      <td>
                        <div className="supSub">
                          <span className="supSubIcon">📞</span>
                          {s.phone}
                        </div>
                        <div className="supSub">
                          <span className="supSubIcon">✉️</span>
                          {s.email}
                        </div>
                      </td>

                      <td>{s.taxId}</td>

                      <td>{formatVND(s.totalValue)}</td>

                      <td>
                        <span
                          className={
                            s.status === "Đang hợp tác"
                              ? "supStatusOk"
                              : "supStatusStop"
                          }
                        >
                          {s.status}
                        </span>
                      </td>

                      <td style={{ textAlign: "center" }}>
                        <div className="supActions">
                          <button
                            className="supIconBtn supEye"
                            title="Lịch sử giao dịch"
                            onClick={() => {
                              setHistorySupplier(s);
                              setOpenHistory(true);
                            }}
                          >
                            <EyeIcon />
                          </button>

                          <button
                            className="supIconBtn supEdit"
                            title="Sửa"
                            onClick={() => {
                              setEditing(s);
                              setOpenEdit(true);
                            }}
                          >
                            <EditIcon />
                          </button>

                          <button
                            className="supIconBtn supTrash"
                            title="Xóa"
                            onClick={() => {
                              setDeleting(s);
                              setOpenDel(true);
                            }}
                          >
                            <TrashIcon />
                          </button>
                        </div>
                      </td>
                    </tr>
                  ))}

                  {filtered.length === 0 && (
                    <tr>
                      <td colSpan={7} className="supEmpty">
                        Không có dữ liệu
                      </td>
                    </tr>
                  )}
                </tbody>
              </table>
            </div>
          </div>
        </div>
      </div>

      {/* Modal: Thêm */}
      <SupplierUpsertModal
        open={openAdd}
        mode="create"
        supplier={null}
        onClose={() => setOpenAdd(false)}
        onSubmit={onCreate}
      />

      {/* Modal: Sửa */}
      <SupplierUpsertModal
        open={openEdit}
        mode="edit"
        supplier={editing}
        onClose={() => setOpenEdit(false)}
        onSubmit={onEdit}
      />

      {/* Modal: Lịch sử giao dịch */}
      <SupplierHistoryModal
        open={openHistory}
        supplier={historySupplier}
        txMap={mockSupplierTx}
        onClose={() => setOpenHistory(false)}
      />

      {/* Xóa (dùng dialog xanh bạn đã có) */}
      <ConfirmDeleteDialog
        open={openDel}
        onClose={() => setOpenDel(false)}
        title="Xóa nhà cung cấp"
        onConfirm={onDelete}
      />
    </div>
  );
}

function EyeIcon() {
  return (
    <svg width="20" height="20" viewBox="0 0 24 24" fill="none">
      <path
        d="M2.4 12s3.4-7.2 9.6-7.2S21.6 12 21.6 12 18.2 19.2 12 19.2 2.4 12 2.4 12Z"
        stroke="currentColor"
        strokeWidth="2"
      />
      <circle cx="12" cy="12" r="3" stroke="currentColor" strokeWidth="2" />
    </svg>
  );
}

function EditIcon() {
  return (
    <svg width="20" height="20" viewBox="0 0 24 24" fill="none">
      <path
        d="M4 20h4l10.6-10.6a1.5 1.5 0 0 0 0-2.1L16.7 4.4a1.5 1.5 0 0 0-2.1 0L4 15v5Z"
        stroke="currentColor"
        strokeWidth="2"
      />
      <path
        d="M13.5 5.5 18.5 10.5"
        stroke="currentColor"
        strokeWidth="2"
      />
    </svg>
  );
}

function TrashIcon() {
  return (
    <svg width="20" height="20" viewBox="0 0 24 24" fill="none">
      <path
        d="M6 7h12"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
      />
      <path
        d="M9 7V5.5A1.5 1.5 0 0 1 10.5 4h3A1.5 1.5 0 0 1 15 5.5V7"
        stroke="currentColor"
        strokeWidth="2"
      />
      <path
        d="M7 7l1 14h8l1-14"
        stroke="currentColor"
        strokeWidth="2"
      />
      <path
        d="M10 11v6M14 11v6"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
      />
    </svg>
  );
}
