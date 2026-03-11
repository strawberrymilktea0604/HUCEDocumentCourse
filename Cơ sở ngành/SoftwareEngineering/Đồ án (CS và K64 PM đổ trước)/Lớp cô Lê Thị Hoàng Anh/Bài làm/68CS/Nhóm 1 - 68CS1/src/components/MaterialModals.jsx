import React, { useMemo, useState } from "react";
import Modal from "./Modal.jsx";

export function MaterialDetailModal({ open, onClose, material }) {
  if (!material) return null;

  return (
    <Modal open={open} onClose={onClose} title={`Chi tiết nguyên liệu - ${material.code}`} width="min(1200px, 96vw)">
      <div className="detailGrid">
        <div className="kv">
          <div className="k">Mã nguyên liệu</div>
          <div className="v">{material.code}</div>
        </div>
        <div className="kv">
          <div className="k">Tên nguyên liệu</div>
          <div className="v">{material.name}</div>
        </div>

        <div className="kv">
          <div className="k">Danh mục</div>
          <div className="v">{material.category}</div>
        </div>
        <div className="kv">
          <div className="k">Nhà cung cấp</div>
          <div className="v">{material.supplier}</div>
        </div>

        <div className="kv">
          <div className="k">Đơn vị tính</div>
          <div className="v">{material.unit}</div>
        </div>
        <div className="kv">
          <div className="k">Tồn tối thiểu</div>
          <div className="v">{material.minStock}</div>
        </div>

        <div className="kv">
          <div className="k">Tổng tồn kho hiện tại</div>
          <div className="v">{material.totalStock}</div>
        </div>
        <div className="kv">
          <div className="k">Vị trí lưu trữ</div>
          <div className="v">{material.location}</div>
        </div>
      </div>

      <div className="kv">
        <div className="k">Quy cách bảo quản</div>
        <div className="v" style={{ fontSize: 22 }}>{material.storage}</div>
      </div>

      <div className="hrLine" />

      <div className="tableTitle">Danh sách lô hàng</div>
      <table className="table">
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
          {material.lots.map((l) => (
            <tr key={l.lot}>
              <td>{l.lot}</td>
              <td>{l.mfg}</td>
              <td>{l.exp}</td>
              <td>{l.initQty}</td>
              <td>{l.currentQty}</td>
              <td>{l.location}</td>
              <td className={l.status === "Hết hàng" ? "stDanger" : "stOk"}>{l.status}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </Modal>
  );
}

function Field({ label, required, children }) {
  return (
    <div className="field">
      <label>
        {label}{required && <span className="req">*</span>}
      </label>
      {children}
    </div>
  );
}

export function MaterialCreateModal({ open, onClose, onSubmit }) {
  const [form, setForm] = useState({
    name: "",
    supplier: "",
    category: "",
    baseUnit: "Kg",
    defaultLocation: "",
    minStock: "",
    storage: "",
    status: "Đang sử dụng",
  });

  const set = (k) => (e) => setForm((p) => ({ ...p, [k]: e.target.value }));

  return (
    <Modal open={open} onClose={onClose} title="Thêm nguyên liệu mới" width="min(1100px, 96vw)">
      <div className="formGrid">
        <Field label="Tên nguyên liệu" required>
          <input className="input" value={form.name} onChange={set("name")} />
        </Field>

        <Field label="Nhà cung cấp" required>
          <select className="input select" value={form.supplier} onChange={set("supplier")}>
            <option value="">Chọn nhà cung cấp</option>
            <option value="Công ty Hạt điều BP">Công ty Hạt điều BP</option>
            <option value="NCC Sữa tươi">NCC Sữa tươi</option>
          </select>
        </Field>

        <Field label="Danh mục" required>
          <input className="input" value={form.category} onChange={set("category")} />
        </Field>

        <Field label="Đơn vị tính cơ sở" required>
          <select className="input select" value={form.baseUnit} onChange={set("baseUnit")}>
            <option>Kg</option>
            <option>Hộp</option>
            <option>Gói</option>
          </select>
        </Field>

        <Field label="Vị trí lưu trữ mặc định" required>
          <input className="input" placeholder="VD: Hàng 2 - Kệ A" value={form.defaultLocation} onChange={set("defaultLocation")} />
        </Field>

        <Field label="Tồn tối thiểu" required>
          <input className="input" value={form.minStock} onChange={set("minStock")} />
        </Field>

        <Field label="Quy cách bảo quản" required>
          <input className="input" value={form.storage} onChange={set("storage")} />
        </Field>

        <Field label="Trạng thái" required>
          <select className="input select" value={form.status} onChange={set("status")}>
            <option>Đang sử dụng</option>
            <option>Ngừng sử dụng</option>
          </select>
        </Field>
      </div>

      <div className="modalActions">
        <button className="btn" onClick={onClose}>Hủy</button>
        <button
          className="btn btnPrimary"
          onClick={() => {
            onSubmit?.(form);
            onClose?.();
          }}
        >
          Thêm
        </button>
      </div>
    </Modal>
  );
}

export function MaterialEditModal({ open, onClose, material, onSubmit }) {
  const init = useMemo(() => ({
    name: material?.name ?? "",
    supplier: material?.supplier ?? "",
    category: material?.category ?? "",
    baseUnit: material?.unit ?? "Kg",
    defaultLocation: material?.location ?? "",
    minStock: material?.minStock?.replace(" Kg", "") ?? "100",
    storage: material?.storage ?? "",
    status: "Đang sử dụng",
  }), [material]);

  const [form, setForm] = useState(init);

  // reset khi mở
  React.useEffect(() => {
    if (open) setForm(init);
  }, [open, init]);

  const set = (k) => (e) => setForm((p) => ({ ...p, [k]: e.target.value }));

  return (
    <Modal open={open} onClose={onClose} title={`Sửa thông tin nguyên liệu - ${material?.code ?? ""}`} width="min(1100px, 96vw)">
      <div className="formGrid">
        <Field label="Tên nguyên liệu" required>
          <input className="input" value={form.name} onChange={set("name")} />
        </Field>

        <Field label="Nhà cung cấp" required>
          <select className="input select" value={form.supplier} onChange={set("supplier")}>
            <option value="">Chọn nhà cung cấp</option>
            <option value="Công ty hạt điều BP">Công ty hạt điều BP</option>
            <option value="Công ty Hạt điều BP">Công ty Hạt điều BP</option>
          </select>
        </Field>

        <Field label="Danh mục" required>
          <input className="input" value={form.category} onChange={set("category")} />
        </Field>

        <Field label="Đơn vị tính cơ sở" required>
          <select className="input select" value={form.baseUnit} onChange={set("baseUnit")}>
            <option>Kg</option>
            <option>Hộp</option>
          </select>
        </Field>

        <Field label="Vị trí lưu trữ mặc định" required>
          <input className="input" value={form.defaultLocation} onChange={set("defaultLocation")} />
        </Field>

        <Field label="Tồn tối thiểu" required>
          <input className="input" value={form.minStock} onChange={set("minStock")} />
        </Field>

        <Field label="Quy cách bảo quản" required>
          <input className="input" value={form.storage} onChange={set("storage")} />
        </Field>

        <Field label="Trạng thái" required>
          <select className="input select" value={form.status} onChange={set("status")}>
            <option>Đang sử dụng</option>
            <option>Ngừng sử dụng</option>
          </select>
        </Field>
      </div>

      <div className="modalActions">
        <button className="btn" onClick={onClose}>Hủy</button>
        <button
          className="btn btnPrimary"
          onClick={() => {
            onSubmit?.(form);
            onClose?.();
          }}
        >
          Cập nhật
        </button>
      </div>
    </Modal>
  );
}
