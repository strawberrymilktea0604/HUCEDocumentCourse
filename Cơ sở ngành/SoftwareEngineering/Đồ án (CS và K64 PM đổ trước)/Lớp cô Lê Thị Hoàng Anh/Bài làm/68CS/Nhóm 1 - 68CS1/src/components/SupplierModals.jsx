import React, { useEffect, useMemo, useState } from "react";
import Modal from "./Modal.jsx";

function formatVND(n) {
  const s = String(Math.round(Number(n) || 0));
  return s.replace(/\B(?=(\d{3})+(?!\d))/g, ".") + " đ";
}

function parseDateVN(ddmmyyyy) {
  // dd/mm/yyyy
  const [d, m, y] = (ddmmyyyy || "").split("/").map((x) => parseInt(x, 10));
  if (!d || !m || !y) return 0;
  return new Date(y, m - 1, d).getTime();
}

function Field({ label, required, children }) {
  return (
    <div className="supField">
      <label>
        {label}
        {required && <span className="req">*</span>}
      </label>
      {children}
    </div>
  );
}

/** Modal: Thêm/Sửa NCC */
export function SupplierUpsertModal({ open, mode, supplier, onClose, onSubmit }) {
  const isEdit = mode === "edit";

  const init = useMemo(() => {
    if (!supplier) {
      return {
        code: "",
        name: "",
        address: "",
        phone: "",
        email: "",
        taxId: "",
        status: "Đang hợp tác",
        note: "",
      };
    }
    return {
      code: supplier.code,
      name: supplier.name,
      address: supplier.address,
      phone: supplier.phone,
      email: supplier.email,
      taxId: supplier.taxId,
      status: supplier.status || "Đang hợp tác",
      note: supplier.note || "",
    };
  }, [supplier]);

  const [form, setForm] = useState(init);

  useEffect(() => {
    if (open) setForm(init);
  }, [open, init]);

  const set = (k) => (e) => setForm((p) => ({ ...p, [k]: e.target.value }));

  const title = isEdit
    ? `Sửa thông tin nhà cung cấp - ${supplier?.code || ""}`
    : "Thêm nhà cung cấp mới";

  return (
    <Modal open={open} onClose={onClose} title={title} width="min(1100px, 96vw)">
      <div className="supForm">
        <Field label="Tên nhà cung cấp" required>
          <input className="input" value={form.name} onChange={set("name")} />
        </Field>

        <Field label="Địa chỉ" required>
          <input
            className="input"
            value={form.address}
            onChange={set("address")}
          />
        </Field>

        <div className="supFormGrid2">
          <Field label="Điện thoại" required>
            <input
              className="input"
              value={form.phone}
              onChange={set("phone")}
            />
          </Field>

          <Field label="Email" required>
            <input
              className="input"
              value={form.email}
              onChange={set("email")}
            />
          </Field>
        </div>

        <div className="supFormGrid2">
          <Field label="Mã số thuế" required>
            <input
              className="input"
              value={form.taxId}
              onChange={set("taxId")}
            />
          </Field>

          <Field label="Trạng thái">
            <select className="input select" value={form.status} onChange={set("status")}>
              <option>Đang hợp tác</option>
              <option>Ngừng hợp tác</option>
            </select>
          </Field>
        </div>

        <Field label="Ghi chú">
          <input className="input" value={form.note} onChange={set("note")} />
        </Field>
      </div>

      <div className="modalActions">
        <button className="btn" onClick={onClose}>
          Hủy
        </button>
        <button
          className="btn btnPrimary"
          onClick={() => {
            if (
              !form.name.trim() ||
              !form.address.trim() ||
              !form.phone.trim() ||
              !form.email.trim() ||
              !form.taxId.trim()
            ) {
              alert("Vui lòng nhập đầy đủ các trường bắt buộc.");
              return;
            }

            const payload = {
              ...(isEdit ? { code: form.code } : {}),
              name: form.name.trim(),
              address: form.address.trim(),
              phone: form.phone.trim(),
              email: form.email.trim(),
              taxId: form.taxId.trim(),
              status: form.status,
              note: form.note,
            };

            if (isEdit) {
              onSubmit?.({ code: supplier.code, ...payload });
            } else {
              onSubmit?.({ ...payload });
            }
            onClose?.();
          }}
        >
          {isEdit ? "Cập nhật" : "Thêm"}
        </button>
      </div>
    </Modal>
  );
}

/** Modal: Lịch sử giao dịch */
export function SupplierHistoryModal({ open, onClose, supplier, txMap }) {
  const tx = supplier ? txMap?.[supplier.code] || [] : [];

  const stats = useMemo(() => {
    const totalCount = tx.length;
    const totalValue = tx.reduce((a, b) => a + (Number(b.value) || 0), 0);
    const latest = tx
      .slice()
      .sort((a, b) => parseDateVN(b.date) - parseDateVN(a.date))[0]?.date;

    return { totalCount, totalValue, latest: latest || "—" };
  }, [tx]);

  return (
    <Modal
      open={open}
      onClose={onClose}
      title={
        supplier ? `Lịch sử giao dịch - ${supplier.name}` : "Lịch sử giao dịch"
      }
      width="min(1400px, 98vw)"
    >
      {supplier && <div className="supHistorySub">Mã NCC: {supplier.code}</div>}

      <div className="supHistoryCards">
        <div className="supCardStat supCardBlue">
          <div className="supCardStatTitle">Tổng số giao dịch</div>
          <div className="supCardStatValue">{stats.totalCount}</div>
        </div>

        <div className="supCardStat supCardGreen">
          <div className="supCardStatTitle">Tổng giá trị</div>
          <div className="supCardStatValue">{formatVND(stats.totalValue)}</div>
        </div>

        <div className="supCardStat supCardPurple">
          <div className="supCardStatTitle">Giao dịch gần nhất</div>
          <div className="supCardStatValue">{stats.latest}</div>
        </div>
      </div>

      <div className="supHistoryTableOuter">
        <table className="supHistoryTable">
          <thead>
            <tr>
              <th>Ngày GD</th>
              <th>Loại GD</th>
              <th>Mã chứng từ</th>
              <th>Nguyên liệu</th>
              <th>Số lượng</th>
              <th>Giá trị</th>
              <th>Trạng thái</th>
            </tr>
          </thead>
          <tbody>
            {tx.map((t, idx) => (
              <tr key={idx}>
                <td>{t.date}</td>
                <td>{t.type}</td>
                <td>{t.doc}</td>
                <td>{t.item}</td>
                <td>{t.qty}</td>
                <td>{formatVND(t.value)}</td>
                <td className="supDone">{t.status}</td>
              </tr>
            ))}
            {tx.length === 0 && (
              <tr>
                <td colSpan={7} className="supEmpty">
                  Không có dữ liệu giao dịch
                </td>
              </tr>
            )}
          </tbody>
        </table>
      </div>
    </Modal>
  );
}
