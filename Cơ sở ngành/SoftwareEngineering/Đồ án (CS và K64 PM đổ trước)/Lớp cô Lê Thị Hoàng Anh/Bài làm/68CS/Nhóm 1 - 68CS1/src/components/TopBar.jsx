import React from "react";
import { NutMilkLogo, Icon } from "./Icons.jsx";

export default function TopBar({ titleLeft = "NutMilk - Quản lý Kho", year = "Năm 2025", user, bellCount = 0 }) {
  return (
    <div className="topbar">
      <div className="brand">
        <NutMilkLogo size={46} />
        <div className="brandTitle">
          <div className="t1">{titleLeft}</div>
          <div className="t2">{year}</div>
        </div>
      </div>

      <div className="bellWrap" title="Thông báo">
        <Icon name="bell" size={22} />
        <div className="bellBadge">{bellCount}</div>
      </div>

      <div className="search">
        <Icon name="search" size={18} />
        <input placeholder="Tìm kiếm..." />
      </div>

      <div className="userBox">
        <div className="avatar"><Icon name="user" size={22} /></div>
        <div className="userText">
          <div className="idname">{user.userId} - {user.fullName}</div>
          <div className="role">{user.role}</div>
        </div>
      </div>
    </div>
  );
}
