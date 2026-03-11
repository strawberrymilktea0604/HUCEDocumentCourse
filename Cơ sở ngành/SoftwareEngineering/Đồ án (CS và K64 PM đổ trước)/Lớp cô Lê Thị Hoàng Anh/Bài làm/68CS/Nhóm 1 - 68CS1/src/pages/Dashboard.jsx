import React, { useState } from "react";
import TopBar from "../components/TopBar.jsx";
import MenuPopover from "../components/MenuPopover.jsx";
import QuickActions from "../components/QuickActions.jsx";
import { NotificationPanel, ExpiringPanel } from "../components/DashboardPanels.jsx";
import { Icon } from "../components/Icons.jsx";
import { currentUser, expiring, newMaterials, notifications, todayMoves, materialNVL01 } from "../data/mock.js";
import { MaterialCreateModal, MaterialDetailModal, MaterialEditModal } from "../components/MaterialModals.jsx";

export default function Dashboard() {
  const [menuOpen, setMenuOpen] = useState(false);

  // Modals như ảnh bạn gửi
  const [openDetail, setOpenDetail] = useState(false);
  const [openCreate, setOpenCreate] = useState(false);
  const [openEdit, setOpenEdit] = useState(false);

  return (
    <div>
      <TopBar user={currentUser} bellCount={0} />

      <div className="dashboardWrap">
        {/* Left rail + menu */}
        <div className="leftRail">
          <button className="menuBtn" onClick={() => setMenuOpen((s) => !s)} aria-label="Menu">
            <Icon name="menu" size={22} />
          </button>
        </div>

        {/* Popover menu như ảnh */}
        <div style={{ position: "relative", width: 0 }}>
          <MenuPopover open={menuOpen} onClose={() => setMenuOpen(false)} />
        </div>

        <div className="mainGrid">
          <NotificationPanel notifications={notifications} />
          <ExpiringPanel expiring={expiring} />

          <QuickActions />

          {/* Bottom row */}
          <div className="bottomRow">
            <div className="bigList">
              <div className="bigHead" style={{ background: "#7aa454" }}>Hàng nhập/xuất hôm nay</div>
              <div className="bigBody">
                {todayMoves.map((m, idx) => (
                  <div
                    key={idx}
                    className="li"
                    style={{
                      background: m.dir === "in" ? "rgba(124,207,79,.22)" : "rgba(242,196,0,.22)",
                      borderLeft: `10px solid ${m.dir === "in" ? "rgba(47,159,103,.65)" : "rgba(207,150,0,.65)"}`
                    }}
                  >
                    <div className="liLeft">
                      <div style={{ color: "rgba(32,48,70,.75)" }}>
                        <Icon name={m.dir === "in" ? "arrowDown" : "arrowUp"} size={22} />
                      </div>
                      <div>
                        <div className="liTitle">{m.name}</div>
                        <div className="liSub">{m.qty}</div>
                      </div>
                    </div>
                    <div className="time">{m.time}</div>
                  </div>
                ))}
              </div>
            </div>

            <div className="bigList">
              <div className="bigHead" style={{ background: "#f2c400" }}>Nguyên liệu mới</div>
              <div className="bigBody">
                {newMaterials.map((n, idx) => (
                  <div
                    key={idx}
                    className="li"
                    style={{
                      background: "rgba(242,196,0,.18)",
                      borderLeft: "10px solid rgba(242,196,0,.75)",
                      cursor: idx === 0 ? "pointer" : "default"
                    }}
                    onClick={() => {
                      // demo: click item đầu mở modal chi tiết như ảnh NVL01
                      if (idx === 0) setOpenDetail(true);
                    }}
                  >
                    <div>
                      <div className="liTitle">{n.code} - {n.name}</div>
                      <div className="liSub">Đơn vị tính: {n.unit}</div>
                    </div>
                  </div>
                ))}

                <div style={{ display: "flex", gap: 12, marginTop: 6 }}>
                  <button className="btn" onClick={() => setOpenEdit(true)}>Mở modal sửa (demo)</button>
                  <button className="btn btnPrimary" onClick={() => setOpenCreate(true)}>Thêm nguyên liệu (demo)</button>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>

      {/* Modals */}
      <MaterialDetailModal
        open={openDetail}
        onClose={() => setOpenDetail(false)}
        material={materialNVL01}
      />
      <MaterialCreateModal
        open={openCreate}
        onClose={() => setOpenCreate(false)}
        onSubmit={(payload) => console.log("create:", payload)}
      />
      <MaterialEditModal
        open={openEdit}
        onClose={() => setOpenEdit(false)}
        material={materialNVL01}
        onSubmit={(payload) => console.log("edit:", payload)}
      />
    </div>
  );
}
