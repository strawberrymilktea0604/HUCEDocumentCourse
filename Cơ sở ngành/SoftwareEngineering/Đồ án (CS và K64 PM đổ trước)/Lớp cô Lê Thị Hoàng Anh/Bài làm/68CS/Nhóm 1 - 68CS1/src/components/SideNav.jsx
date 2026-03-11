import React from "react";
import { useLocation, useNavigate } from "react-router-dom";

export default function SideNav() {
  const nav = useNavigate();
  const { pathname } = useLocation();

  const items = [
    { to: "/dashboard", label: "Trang chủ", icon: "🏠" },
    { to: "/profile", label: "Thông tin cá nhân", icon: "👤" },
    { to: "/users", label: "Quản lý người dùng", icon: "👥" },
    { to: "/stock-out", label: "Xuất kho", icon: "📦" },
    { to: "/stock-in", label: "Nhập kho", icon: "📥" },
    { to: "/materials", label: "Nguyên vật liệu", icon: "🧾" },
    { to: "/suppliers", label: "Nhà cung cấp", icon: "🏭" },
    { to: "/inventory", label: "Kiểm kê", icon: "✅" },
  ];

  return (
    <div className="side">
      {items.map((it) => {
        const active = pathname === it.to;
        return (
          <div
            key={it.to}
            className={"sideItem" + (active ? " active" : "")}
            onClick={() => nav(it.to)}
          >
            <span className="sideEmoji">{it.icon}</span>
            <span>{it.label}</span>
          </div>
        );
      })}
    </div>
  );
}
