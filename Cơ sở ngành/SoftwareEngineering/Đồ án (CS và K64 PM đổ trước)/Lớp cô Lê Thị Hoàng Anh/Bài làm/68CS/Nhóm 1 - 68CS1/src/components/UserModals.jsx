import React, { useEffect, useMemo, useState } from "react";
import Modal from "./Modal.jsx";

function Field({ label, required, children }) {
  return (
    <div className="field">
      <label>
        {label}
        {required && <span className="req">*</span>}
      </label>
      {children}
    </div>
  );
}

const ROLES = ["Quản lý", "Nhân viên kho", "Bộ phận sản xuất"];
const STATUSES = ["Hoạt động", "Ngừng hoạt động"];

export function UserCreateModal({ open, onClose, onSubmit }) {
  const [form, setForm] = useState({
    userId: "",
    fullName: "",
    username: "",
    password: "",
    role: "Nhân viên kho",
    email: "",
    phone: "",
    status: "Hoạt động",
  });

  useEffect(() => {
    if (!open) return;
    setForm({
      userId: "",
      fullName: "",
      username: "",
      password: "",
      role: "Nhân viên kho",
      email: "",
      phone: "",
      status: "Hoạt động",
    });
  }, [open]);

  const set = (k) => (e) => setForm((p) => ({ ...p, [k]: e.target.value }));

  return (
    <Modal open={open} onClose={onClose} title="Thêm người dùng mới" width="min(1100px, 96vw)">
      <div className="formGrid">
        <Field label="Mã người dùng" required>
          <input className="input" value={form.userId} onChange={set("userId")} />
        </Field>

        <Field label="Họ và tên" required>
          <input className="input" value={form.fullName} onChange={set("fullName")} />
        </Field>

        <Field label="Tên đăng nhập" required>
          <input className="input" value={form.username} onChange={set("username")} />
        </Field>

        <Field label="Mật khẩu" required>
          <input className="input" type="password" value={form.password} onChange={set("password")} />
        </Field>

        <Field label="Vai trò" required>
          <select className="input select" value={form.role} onChange={set("role")}>
            {ROLES.map((r) => (
              <option key={r}>{r}</option>
            ))}
          </select>
        </Field>

        <Field label="Email" required>
          <input className="input" value={form.email} onChange={set("email")} />
        </Field>

        <Field label="Số điện thoại" required>
          <input className="input" value={form.phone} onChange={set("phone")} />
        </Field>

        <Field label="Trạng thái" required>
          <select className="input select" value={form.status} onChange={set("status")}>
            {STATUSES.map((s) => (
              <option key={s}>{s}</option>
            ))}
          </select>
        </Field>
      </div>

      <div className="modalActions">
        <button className="btn" onClick={onClose}>Hủy</button>
        <button
          className="btn btnPrimary"
          onClick={() => {
            // validate tối thiểu
            const required = ["userId", "fullName", "username", "password", "email", "phone"];
            for (const k of required) {
              if (!String(form[k]).trim()) {
                alert("Vui lòng nhập đầy đủ thông tin bắt buộc.");
                return;
              }
            }
            onSubmit?.({ ...form });
            onClose?.();
          }}
        >
          Thêm
        </button>
      </div>
    </Modal>
  );
}

export function UserEditModal({ open, onClose, user, onSubmit }) {
  const init = useMemo(() => {
    if (!user) {
      return {
        userId: "",
        fullName: "",
        username: "",
        password: "********",
        role: "Nhân viên kho",
        email: "",
        phone: "",
        status: "Hoạt động",
      };
    }
    return {
      userId: user.userId,
      fullName: user.fullName,
      username: user.username,
      password: "********",
      role: user.role,
      email: user.email,
      phone: user.phone,
      status: user.status,
    };
  }, [user]);

  const [form, setForm] = useState(init);

  useEffect(() => {
    if (open) setForm(init);
  }, [open, init]);

  const set = (k) => (e) => setForm((p) => ({ ...p, [k]: e.target.value }));

  return (
    <Modal open={open} onClose={onClose} title="Sửa thông tin người dùng" width="min(1100px, 96vw)">
      <div className="formGrid">
        <Field label="Mã người dùng" required>
          <input className="input" value={form.userId} readOnly />
        </Field>

        <Field label="Họ và tên" required>
          <input className="input" value={form.fullName} onChange={set("fullName")} />
        </Field>

        <Field label="Tên đăng nhập" required>
          <input className="input" value={form.username} onChange={set("username")} />
        </Field>

        <Field label="Mật khẩu">
          <input className="input" type="password" value={form.password} readOnly />
        </Field>

        <Field label="Vai trò">
          <select className="input select" value={form.role} onChange={set("role")}>
            {ROLES.map((r) => (
              <option key={r}>{r}</option>
            ))}
          </select>
        </Field>

        <Field label="Email" required>
          <input className="input" value={form.email} onChange={set("email")} />
        </Field>

        <Field label="Số điện thoại">
          <input className="input" value={form.phone} onChange={set("phone")} />
        </Field>

        <Field label="Trạng thái">
          <select className="input select" value={form.status} onChange={set("status")}>
            {STATUSES.map((s) => (
              <option key={s}>{s}</option>
            ))}
          </select>
        </Field>
      </div>

      <div className="modalActions">
        <button className="btn" onClick={onClose}>Hủy</button>
        <button
          className="btn btnPrimary"
          onClick={() => {
            if (!form.fullName.trim() || !form.username.trim() || !form.email.trim()) {
              alert("Vui lòng nhập đầy đủ thông tin bắt buộc.");
              return;
            }
            onSubmit?.({
              userId: form.userId,
              fullName: form.fullName,
              username: form.username,
              role: form.role,
              email: form.email,
              phone: form.phone,
              status: form.status,
            });
            onClose?.();
          }}
        >
          Cập nhật
        </button>
      </div>
    </Modal>
  );
}

export function ConfirmDeleteDialog({ open, title = "Xóa tài khoản", onClose, onConfirm }) {
  if (!open) return null;

  return (
    <div className="confirmOverlay" onMouseDown={onClose}>
      <div className="confirmBox" onMouseDown={(e) => e.stopPropagation()}>
        <div className="confirmTitle">{title}</div>
        <div className="confirmActions">
          <button className="confirmYes" onClick={onConfirm}>Có</button>
          <button className="confirmNo" onClick={onClose}>Không</button>
        </div>
      </div>
    </div>
  );
}

export function ChangePasswordModal({ open, onClose, onSubmit }) {
  const [oldPw, setOldPw] = useState("");
  const [newPw, setNewPw] = useState("");
  const [cfPw, setCfPw] = useState("");

  useEffect(() => {
    if (!open) return;
    setOldPw("");
    setNewPw("");
    setCfPw("");
  }, [open]);

  const isValidPassword = (p) => {
    // >=8, có chữ hoa, chữ thường, ký tự đặc biệt
    if (p.length < 8) return false;
    if (!/[a-z]/.test(p)) return false;
    if (!/[A-Z]/.test(p)) return false;
    if (!/[^A-Za-z0-9]/.test(p)) return false;
    return true;
  };

  return (
    <Modal open={open} onClose={onClose} title="Đổi mật khẩu" width="min(900px, 96vw)">
      <div className="pwOneCol">
        <Field label="Nhập mật khẩu cũ" required>
          <input className="input" type="password" value={oldPw} onChange={(e) => setOldPw(e.target.value)} />
        </Field>

        <Field label="Nhập mật khẩu mới" required>
          <input className="input" type="password" value={newPw} onChange={(e) => setNewPw(e.target.value)} />
        </Field>

        <Field label="Xác nhận mật khẩu mới" required>
          <input className="input" type="password" value={cfPw} onChange={(e) => setCfPw(e.target.value)} />
        </Field>

        <div className="pwHint">
          Mật khẩu phải bao gồm tối thiểu 8 kí tự gồm Chữ hoa, Chữ thường và Kí tự đặc biệt.
        </div>

        <div className="modalActions">
          <button className="btn" onClick={onClose}>Hủy</button>
          <button
            className="btn btnPrimary"
            onClick={() => {
              if (!oldPw || !newPw || !cfPw) {
                alert("Vui lòng nhập đầy đủ thông tin.");
                return;
              }
              if (newPw !== cfPw) {
                alert("Xác nhận mật khẩu mới không khớp.");
                return;
              }
              if (!isValidPassword(newPw)) {
                alert("Mật khẩu mới chưa đúng yêu cầu.");
                return;
              }
              onSubmit?.({ oldPw, newPw });
              onClose?.();
            }}
          >
            Cập nhật
          </button>
        </div>
      </div>
    </Modal>
  );
}
