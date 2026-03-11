import React from "react";
import { useNavigate } from "react-router-dom";
import { Icon } from "./Icons.jsx";

export default function MenuPopover({ open, onClose }) {
  const nav = useNavigate();
  if (!open) return null;

  const items = [
    { to: "/dashboard", label: "Trang chủ", icon: "home" },
    { to: "/profile", label: "Thông tin cá nhân", icon: "profile" },
    { to: "/users", label: "Quản lý người dùng", icon: "users" },
    { to: "/stock-out", label: "Xuất kho", icon: "boxout" },
    { to: "/stock-in", label: "Nhập kho", icon: "boxin" },
    { to: "/materials", label: "Nguyên vật liệu", icon: "materials" },
    { to: "/suppliers", label: "Nhà cung cấp", icon: "supplier" },
    { to: "/inventory", label: "Kiểm kê", icon: "checklist" },
  ];

  return (
    <div className="popover" onMouseLeave={onClose}>
      {items.map((it) => (
        <div
          key={it.to}
          className="popItem"
          onClick={() => {
            nav(it.to);
            onClose?.();
          }}
        >
          <span style={{ color: "#1f6aa8" }}><Icon name={it.icon} size={22} /></span>
          <span>{it.label}</span>
        </div>
      ))}
    </div>
  );
}
