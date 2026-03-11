import React from "react";
import { useNavigate } from "react-router-dom";
import { Icon } from "./Icons.jsx";

export default function QuickActions() {
  const nav = useNavigate();

  const actions = [
    { label: "Quản lý", icon: "users", to: "/users" },
    { label: "Nguyên liệu", icon: "materials", to: "/materials" },
    { label: "Nhà cung cấp", icon: "supplier", to: "/suppliers" },
    { label: "Xuất hàng", icon: "boxout", to: "/stock-out" },
    { label: "Nhập hàng", icon: "boxin", to: "/stock-in" },
    { label: "Kiểm kê", icon: "checklist", to: "/inventory" },
  ];

  return (
    <div className="quickRow">
      {actions.map((a) => (
        <div key={a.label} className="quickCard" onClick={() => nav(a.to)}>
          <div style={{ color: "#1f6aa8" }}>
            <Icon name={a.icon} size={34} />
          </div>
          <div className="label">{a.label}</div>
        </div>
      ))}
    </div>
  );
}
