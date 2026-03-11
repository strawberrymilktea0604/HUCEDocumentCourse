import React from "react";
import { Icon } from "./Icons.jsx";

export function NotificationPanel({ notifications }) {
  return (
    <div className="panel">
      <div className="panelHead" style={{ background: "var(--notifHead)" }}>
        <Icon name="bell" size={22} />
        <span>Thông báo</span>
      </div>
      <div className="panelBody">
        {notifications.map((n, idx) => (
          <div className="msgRow" key={idx}>
            <div className="msgFrom">
              <div className="lbl">Từ</div>
              <div className="val">{n.from}</div>
            </div>
            <div className="msgTxt">
              <div className="title">{n.title}</div>
              <div className="sub">{n.sub}</div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}

export function ExpiringPanel({ expiring }) {
  return (
    <div className="panel">
      <div className="panelHead" style={{ background: "var(--expHead)" }}>
        <span style={{ display: "grid", placeItems: "center", width: 30, height: 30, borderRadius: 999, border: "2px solid rgba(255,255,255,.8)" }}>
          <span style={{ fontWeight: 900, fontSize: 14 }}>!</span>
        </span>
        <span>Hàng sắp hết hạn</span>
      </div>
      <div className="panelBody">
        {expiring.map((e, idx) => (
          <div className="expItem" key={idx}>
            <div>
              <div className="name">{e.name}</div>
              <div className="meta">Số lượng: {e.qty}</div>
            </div>
            <div className="expRight">
              <div className="meta" style={{ fontWeight: 800 }}>HSD: {e.hsd}</div>
              <span className="pill pillDanger">{e.days} ngày</span>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
