import React, { useEffect, useMemo, useState } from "react";
import TopBar from "../components/TopBar.jsx";
import SideNav from "../components/SideNav.jsx";
import { currentUser } from "../data/mock.js";

/** ====== Icon nhỏ (để giống cột Thao tác: xem / sửa / xóa) ====== */
function EyeIcon() {
  return (
    <svg width="18" height="18" viewBox="0 0 24 24" className="nmActEye">
      <path
        d="M12 5c5.5 0 9.7 4.3 11 7-1.3 2.7-5.5 7-11 7S2.3 14.7 1 12c1.3-2.7 5.5-7 11-7Zm0 3.2a3.8 3.8 0 1 0 0 7.6 3.8 3.8 0 0 0 0-7.6Z"
        fill="currentColor"
      />
    </svg>
  );
}
function PencilIcon() {
  return (
    <svg width="18" height="18" viewBox="0 0 24 24" className="nmActEdit">
      <path
        d="M3 17.25V21h3.75L19.81 7.94l-3.75-3.75L3 17.25Zm18-10.5a1 1 0 0 0 0-1.41l-1.34-1.34a1 1 0 0 0-1.41 0l-1.06 1.06 3.75 3.75 1.06-1.06Z"
        fill="currentColor"
      />
    </svg>
  );
}
function TrashIcon() {
  return (
    <svg width="18" height="18" viewBox="0 0 24 24" className="nmActDel">
      <path
        d="M6 7h12l-1 14H7L6 7Zm3-3h6l1 2H8l1-2Z"
        fill="currentColor"
      />
    </svg>
  );
}

/** ====== Modal khung chung giống ảnh ====== */
function ModalShell({ open, title, onClose, children, width = 1200 }) {
  if (!open) return null;

  return (
    <div className="nmModalOverlay" onMouseDown={onClose}>
      <div
        className="nmModal"
        style={{ width }}
        onMouseDown={(e) => e.stopPropagation()}
      >
        <div className="nmModalHead">
          <div className="nmModalTitle">{title}</div>
          <button className="nmModalClose" onClick={onClose} aria-label="close">
            ×
          </button>
        </div>
        <div className="nmModalDivider" />
        <div className="nmModalBody">{children}</div>
      </div>
    </div>
  );
}

/** ====== Trang Nguyên vật liệu ====== */
export default function Materials() {
  const suppliers = useMemo(
    () => [
      "Công ty Hạt điều BP",
      "Công ty Nuts VN",
      "Công ty Nhựa EPS",
      "Công ty Vinamilk",
      "Công ty Đường BH",
      "Công ty Hạt AN",
    ],
    []
  );

  const categories = useMemo(() => ["Tất cả danh mục", "Hạt", "Bao bì", "Sữa", "Đường"], []);

  const [q, setQ] = useState("");
  const [cat, setCat] = useState("Tất cả danh mục");

  const [rows, setRows] = useState([
    { id: "NVL01", name: "Hạt điều", category: "Hạt", supplier: "Công ty Hạt điều BP", unit: "Kg", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Sau khi bóc bao bì, sử dụng trong 3 ngày" },
    { id: "NVL02", name: "Hạnh nhân", category: "Hạt", supplier: "Công ty Nuts VN", unit: "Kg", stock: 45, min: 50, storage: "Hàng 2 - Kệ A", preserve: "Sử dụng trong 3 ngày" },
    { id: "NVL03", name: "Hộp nhựa", category: "Bao bì", supplier: "Công ty Nhựa EPS", unit: "Chiếc", stock: 400, min: 80, storage: "Hàng 2 - Kệ A", preserve: "Bảo quản nơi khô ráo" },
    { id: "NVL04", name: "Sữa không", category: "Sữa", supplier: "Công ty Vinamilk", unit: "Lít", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Bảo quản lạnh" },
    { id: "NVL05", name: "Sữa có", category: "Sữa", supplier: "Công ty Vinamilk", unit: "Lít", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Bảo quản lạnh" },
    { id: "NVL06", name: "Chai nhựa", category: "Bao bì", supplier: "Công ty Nhựa EPS", unit: "Chiếc", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Bảo quản nơi khô ráo" },
    { id: "NVL07", name: "Đường cát", category: "Đường", supplier: "Công ty Đường BH", unit: "Kg", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Đậy kín sau khi mở" },
    { id: "NVL08", name: "Đường ăn", category: "Đường", supplier: "Công ty Đường BH", unit: "Kg", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Đậy kín sau khi mở" },
    { id: "NVL09", name: "Hạt macca", category: "Hạt", supplier: "Công ty Hạt AN", unit: "Kg", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Sử dụng trong 3 ngày" },
    { id: "NVL10", name: "Hạt Óc chó", category: "Hạt", supplier: "Công ty Hạt AN", unit: "Kg", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Sử dụng trong 3 ngày" },
    { id: "NVL11", name: "Hạt phỉ", category: "Hạt", supplier: "Công ty Hạt AN", unit: "Kg", stock: 450, min: 100, storage: "Hàng 2 - Kệ A", preserve: "Sử dụng trong 3 ngày" },
  ]);

  const stockLabel = (r) => {
    if (r.stock === 0) return "Hết hàng";
    if (r.stock < r.min) return "Tồn thấp";
    return "Tồn đủ";
  };

  const filtered = useMemo(() => {
    return rows.filter((r) => {
      const okCat = cat === "Tất cả danh mục" ? true : r.category === cat;
      const okQ =
        (r.id + " " + r.name + " " + r.category + " " + r.supplier)
          .toLowerCase()
          .includes(q.trim().toLowerCase());
      return okCat && okQ;
    });
  }, [rows, q, cat]);

  const stat = useMemo(() => {
    const total = rows.length;
    const inUse = rows.length; // giống ảnh: 13 / 13 (demo)
    const low = rows.filter((r) => r.stock > 0 && r.stock < r.min).length;
    const out = rows.filter((r) => r.stock === 0).length;
    return { total, inUse, low, out };
  }, [rows]);

  /** ====== Modal states ====== */
  const [openAdd, setOpenAdd] = useState(false);
  const [openEdit, setOpenEdit] = useState(false);
  const [openDetail, setOpenDetail] = useState(false);
  const [picked, setPicked] = useState(null);

  const openDetailOf = (r) => {
    setPicked(r);
    setOpenDetail(true);
  };
  const openEditOf = (r) => {
    setPicked(r);
    setOpenEdit(true);
  };

  /** ====== Form state (Add/Edit) ====== */
  const emptyForm = {
    id: "",
    name: "",
    supplier: "Chọn nhà cung cấp",
    category: "",
    unit: "Kg",
    storage: "",
    min: "",
    preserve: "",
    usageStatus: "Đang sử dụng",
  };

  const [form, setForm] = useState(emptyForm);

  useEffect(() => {
    if (openAdd) setForm(emptyForm);
  }, [openAdd]);

  useEffect(() => {
    if (openEdit && picked) {
      setForm({
        id: picked.id,
        name: picked.name,
        supplier: picked.supplier,
        category: picked.category,
        unit: picked.unit,
        storage: picked.storage,
        min: String(picked.min),
        preserve: picked.preserve || "",
        usageStatus: "Đang sử dụng",
      });
    }
  }, [openEdit, picked]);

  const submitAdd = () => {
    const nextId =
      "NVL" +
      String(
        Math.max(0, ...rows.map((r) => parseInt(r.id.replace("NVL", ""), 10))) + 1
      ).padStart(2, "0");

    const newRow = {
      id: nextId,
      name: form.name.trim(),
      supplier: form.supplier,
      category: form.category.trim(),
      unit: form.unit,
      stock: 0,
      min: Number(form.min || 0),
      storage: form.storage.trim(),
      preserve: form.preserve.trim(),
    };

    setRows((prev) => [newRow, ...prev]);
    setOpenAdd(false);
  };

  const submitEdit = () => {
    setRows((prev) =>
      prev.map((r) =>
        r.id === picked.id
          ? {
              ...r,
              name: form.name.trim(),
              supplier: form.supplier,
              category: form.category.trim(),
              unit: form.unit,
              min: Number(form.min || 0),
              storage: form.storage.trim(),
              preserve: form.preserve.trim(),
            }
          : r
      )
    );
    setOpenEdit(false);
  };

  const deleteRow = (r) => {
    const ok = window.confirm(`Xóa nguyên liệu ${r.id} - ${r.name}?`);
    if (!ok) return;
    setRows((prev) => prev.filter((x) => x.id !== r.id));
  };

  return (
    <div className="nmPage">
      <TopBar user={currentUser} bellCount={0} />

      <div className="nmLayout">
        <SideNav />

        <div className="nmMain">
          <div className="nmPanel">
            <div className="nmPanelTop">
              <div className="nmPanelTitle">Quản lý nguyên vật liệu</div>
            </div>
            <div className="nmPanelTopLine" />

            <div className="nmTools">
              <div className="nmSearch">
                <span className="nmSearchIcon">🔍</span>
                <input
                  className="nmInput"
                  placeholder="Tìm kiếm..."
                  value={q}
                  onChange={(e) => setQ(e.target.value)}
                />
              </div>

              <select
                className="nmSelect"
                value={cat}
                onChange={(e) => setCat(e.target.value)}
              >
                {categories.map((c) => (
                  <option key={c} value={c}>
                    {c}
                  </option>
                ))}
              </select>

              <button className="nmBtnPrimary" onClick={() => setOpenAdd(true)}>
                + Thêm nguyên liệu
              </button>
            </div>

            <div className="nmStats">
              <div className="nmStatCard">
                <div>
                  <div className="nmStatLabel">Tổng nguyên liệu</div>
                  <div className="nmStatValue nmBlue">{stat.total || 13}</div>
                </div>
                <div className="nmStatBadge nmBlueBg">
                  <div className="nmStatBadgeInner" />
                </div>
              </div>

              <div className="nmStatCard">
                <div>
                  <div className="nmStatLabel">Đang sử dụng</div>
                  <div className="nmStatValue nmGreen">{stat.inUse || 13}</div>
                </div>
                <div className="nmStatBadge nmGreenBg">
                  <div className="nmStatBadgeInner" />
                </div>
              </div>

              <div className="nmStatCard">
                <div>
                  <div className="nmStatLabel">Tồn thấp</div>
                  <div className="nmStatValue nmYellow">{stat.low || 1}</div>
                </div>
                <div className="nmStatBadge nmYellowBg">
                  <div className="nmStatBadgeInner" />
                </div>
              </div>

              <div className="nmStatCard">
                <div>
                  <div className="nmStatLabel">Hết hàng</div>
                  <div className="nmStatValue nmRed">{stat.out || 0}</div>
                </div>
                <div className="nmStatBadge nmRedBg">
                  <div className="nmStatBadgeInner" />
                </div>
              </div>
            </div>

            <div className="nmTableWrap">
              <table className="nmTable">
                <thead>
                  <tr>
                    <th>Mã NVL</th>
                    <th>Tên NVL</th>
                    <th>Danh mục</th>
                    <th>Nhà cung cấp</th>
                    <th>Đơn vị</th>
                    <th>Tồn kho</th>
                    <th>Tồn tối thiểu</th>
                    <th>Trạng thái</th>
                    <th>Thao tác</th>
                  </tr>
                </thead>
                <tbody>
                  {filtered.map((r) => (
                    <tr key={r.id}>
                      <td>{r.id}</td>
                      <td>{r.name}</td>
                      <td>{r.category}</td>
                      <td>{r.supplier}</td>
                      <td>{r.unit}</td>
                      <td>{r.stock}</td>
                      <td>{r.min}</td>
                      <td>{stockLabel(r)}</td>
                      <td>
                        <div className="nmActions">
                          <button
                            className="nmIconBtn nmEyeBtn"
                            onClick={() => openDetailOf(r)}
                            title="Xem"
                          >
                            <EyeIcon />
                          </button>

                          <button
                            className="nmIconBtn nmEditBtn"
                            onClick={() => openEditOf(r)}
                            title="Sửa"
                          >
                            <PencilIcon />
                          </button>

                          <button
                            className="nmIconBtn nmDelBtn"
                            onClick={() => deleteRow(r)}
                            title="Xóa"
                          >
                            <TrashIcon />
                          </button>
                        </div>
                      </td>
                    </tr>
                  ))}
                  {filtered.length === 0 && (
                    <tr>
                      <td colSpan={9} className="nmEmpty">
                        Không có dữ liệu
                      </td>
                    </tr>
                  )}
                </tbody>
              </table>
            </div>

            {/* ============ MODAL: ADD ============ */}
            <ModalShell
              open={openAdd}
              onClose={() => setOpenAdd(false)}
              title="Thêm nguyên liệu mới"
              width={1200}
            >
              <div className="nmFormGrid">
                <div className="nmField">
                  <label>
                    Tên nguyên liệu <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.name}
                    onChange={(e) => setForm((p) => ({ ...p, name: e.target.value }))}
                  />
                </div>

                <div className="nmField">
                  <label>
                    Nhà cung cấp <span className="nmReq">*</span>
                  </label>
                  <select
                    className="nmFieldInput"
                    value={form.supplier}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, supplier: e.target.value }))
                    }
                  >
                    <option>Chọn nhà cung cấp</option>
                    {suppliers.map((s) => (
                      <option key={s} value={s}>
                        {s}
                      </option>
                    ))}
                  </select>
                </div>

                <div className="nmField">
                  <label>
                    Danh mục <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.category}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, category: e.target.value }))
                    }
                  />
                </div>

                <div className="nmField">
                  <label>
                    Đơn vị tính cơ sở <span className="nmReq">*</span>
                  </label>
                  <select
                    className="nmFieldInput"
                    value={form.unit}
                    onChange={(e) => setForm((p) => ({ ...p, unit: e.target.value }))}
                  >
                    <option>Kg</option>
                    <option>Lít</option>
                    <option>Chiếc</option>
                  </select>
                </div>

                <div className="nmField">
                  <label>
                    Vị trí lưu trữ mặc định <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    placeholder="VD: Hàng 2 - Kệ A"
                    value={form.storage}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, storage: e.target.value }))
                    }
                  />
                </div>

                <div className="nmField">
                  <label>
                    Tồn tối thiểu <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.min}
                    onChange={(e) => setForm((p) => ({ ...p, min: e.target.value }))}
                  />
                </div>

                <div className="nmField">
                  <label>
                    Quy cách bảo quản <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.preserve}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, preserve: e.target.value }))
                    }
                  />
                </div>

                <div className="nmField">
                  <label>
                    Trạng thái <span className="nmReq">*</span>
                  </label>
                  <select
                    className="nmFieldInput"
                    value={form.usageStatus}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, usageStatus: e.target.value }))
                    }
                  >
                    <option>Đang sử dụng</option>
                    <option>Ngừng sử dụng</option>
                  </select>
                </div>
              </div>

              <div className="nmModalActions">
                <button className="nmBtnOutline" onClick={() => setOpenAdd(false)}>
                  Hủy
                </button>
                <button className="nmBtnPrimary" onClick={submitAdd}>
                  Thêm
                </button>
              </div>
            </ModalShell>

            {/* ============ MODAL: EDIT ============ */}
            <ModalShell
              open={openEdit}
              onClose={() => setOpenEdit(false)}
              title={`Sửa thông tin nguyên liệu - ${picked?.id || ""}`}
              width={1200}
            >
              <div className="nmFormGrid">
                <div className="nmField">
                  <label>
                    Tên nguyên liệu <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.name}
                    onChange={(e) => setForm((p) => ({ ...p, name: e.target.value }))}
                  />
                </div>

                <div className="nmField">
                  <label>
                    Nhà cung cấp <span className="nmReq">*</span>
                  </label>
                  <select
                    className="nmFieldInput"
                    value={form.supplier}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, supplier: e.target.value }))
                    }
                  >
                    {suppliers.map((s) => (
                      <option key={s} value={s}>
                        {s}
                      </option>
                    ))}
                  </select>
                </div>

                <div className="nmField">
                  <label>
                    Danh mục <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.category}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, category: e.target.value }))
                    }
                  />
                </div>

                <div className="nmField">
                  <label>
                    Đơn vị tính cơ sở <span className="nmReq">*</span>
                  </label>
                  <select
                    className="nmFieldInput"
                    value={form.unit}
                    onChange={(e) => setForm((p) => ({ ...p, unit: e.target.value }))}
                  >
                    <option>Kg</option>
                    <option>Lít</option>
                    <option>Chiếc</option>
                  </select>
                </div>

                <div className="nmField">
                  <label>
                    Vị trí lưu trữ mặc định <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.storage}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, storage: e.target.value }))
                    }
                  />
                </div>

                <div className="nmField">
                  <label>
                    Tồn tối thiểu <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.min}
                    onChange={(e) => setForm((p) => ({ ...p, min: e.target.value }))}
                  />
                </div>

                <div className="nmField">
                  <label>
                    Quy cách bảo quản <span className="nmReq">*</span>
                  </label>
                  <input
                    className="nmFieldInput"
                    value={form.preserve}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, preserve: e.target.value }))
                    }
                  />
                </div>

                <div className="nmField">
                  <label>
                    Trạng thái <span className="nmReq">*</span>
                  </label>
                  <select
                    className="nmFieldInput"
                    value={form.usageStatus}
                    onChange={(e) =>
                      setForm((p) => ({ ...p, usageStatus: e.target.value }))
                    }
                  >
                    <option>Đang sử dụng</option>
                    <option>Ngừng sử dụng</option>
                  </select>
                </div>
              </div>

              <div className="nmModalActions">
                <button className="nmBtnOutline" onClick={() => setOpenEdit(false)}>
                  Hủy
                </button>
                <button className="nmBtnPrimary" onClick={submitEdit}>
                  Cập nhật
                </button>
              </div>
            </ModalShell>

            {/* ============ MODAL: DETAIL ============ */}
            <ModalShell
              open={openDetail}
              onClose={() => setOpenDetail(false)}
              title={`Chi tiết nguyên liệu - ${picked?.id || ""}`}
              width={1200}
            >
              {picked && (
                <>
                  <div className="nmDetailGrid">
                    <div className="nmDItem">
                      <div className="nmDLbl">Mã nguyên liệu</div>
                      <div className="nmDVal">{picked.id}</div>
                    </div>
                    <div className="nmDItem">
                      <div className="nmDLbl">Tên nguyên liệu</div>
                      <div className="nmDVal">{picked.name}</div>
                    </div>

                    <div className="nmDItem">
                      <div className="nmDLbl">Danh mục</div>
                      <div className="nmDVal">{picked.category}</div>
                    </div>
                    <div className="nmDItem">
                      <div className="nmDLbl">Nhà cung cấp</div>
                      <div className="nmDVal">{picked.supplier}</div>
                    </div>

                    <div className="nmDItem">
                      <div className="nmDLbl">Đơn vị tính</div>
                      <div className="nmDVal">{picked.unit}</div>
                    </div>
                    <div className="nmDItem">
                      <div className="nmDLbl">Tồn tối thiểu</div>
                      <div className="nmDVal">
                        {picked.min} {picked.unit}
                      </div>
                    </div>

                    <div className="nmDItem">
                      <div className="nmDLbl">Tổng tồn kho hiện tại</div>
                      <div className="nmDVal">
                        {picked.stock} {picked.unit}
                      </div>
                    </div>
                    <div className="nmDItem">
                      <div className="nmDLbl">Vị trí lưu trữ</div>
                      <div className="nmDVal">{picked.storage}</div>
                    </div>

                    <div className="nmDItem nmDItemFull">
                      <div className="nmDLbl">Quy cách bảo quản</div>
                      <div className="nmDVal">{picked.preserve}</div>
                    </div>
                  </div>

                  <div className="nmDetailDivider" />

                  <div className="nmLotsTitle">Danh sách lô hàng</div>
                  <div className="nmLotsWrap">
                    <table className="nmLotsTable">
                      <thead>
                        <tr>
                          <th>Mã lô</th>
                          <th>Ngày sản xuất</th>
                          <th>Hạn sử dụng</th>
                          <th>SL ban đầu</th>
                          <th>SL hiện tại</th>
                          <th>Vị trí</th>
                          <th>Trạng thái</th>
                        </tr>
                      </thead>
                      <tbody>
                        <tr>
                          <td>LO202511</td>
                          <td>12/11/2025</td>
                          <td>12/11/2026</td>
                          <td>500 Kg</td>
                          <td>0 Kg</td>
                          <td>Hàng 2 - Kệ A</td>
                          <td className="nmBadRed">Hết hàng</td>
                        </tr>
                        <tr>
                          <td>LO202512</td>
                          <td>01/12/2025</td>
                          <td>01/12/2026</td>
                          <td>500 Kg</td>
                          <td>450 Kg</td>
                          <td>Hàng 2 - Kệ A</td>
                          <td className="nmBadGreen">Còn hàng</td>
                        </tr>
                      </tbody>
                    </table>
                  </div>
                </>
              )}
            </ModalShell>
          </div>
        </div>
      </div>
    </div>
  );
}
