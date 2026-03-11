import React, { useState } from "react";
import TopBar from "../components/TopBar.jsx";
import SideNav from "../components/SideNav.jsx";
import { Icon } from "../components/Icons.jsx";
import { currentUser } from "../data/mock.js";
import { ChangePasswordModal } from "../components/UserModals.jsx";

export default function Profile() {
  const [openPw, setOpenPw] = useState(false);

  return (
    <div>
      <TopBar user={currentUser} bellCount={0} />

      <div className="profileWrap">
        {/* ✅ Thay block sidebar cũ bằng SideNav */}
        <SideNav />

        <div className="profileCard">
          <div className="profileHead">
            <div
              className="avatar"
              style={{
                background: "rgba(255,255,255,.12)",
                borderColor: "rgba(255,255,255,.35)",
                color: "#fff",
              }}
            >
              <Icon name="user" size={22} />
            </div>
            <div style={{ lineHeight: 1.1 }}>
              <div style={{ fontWeight: 900 }}>{currentUser.fullName}</div>
              <div style={{ fontWeight: 700, opacity: 0.9 }}>
                {currentUser.role}
              </div>
            </div>
          </div>

          <div className="profileBody">
            <div className="profileTitle">Thông tin tài khoản</div>

            <div className="profileGrid">
              <div className="pRow">
                <div className="pIcon">
                  <Icon name="users" size={22} />
                </div>
                <div>
                  <div className="pLbl">Mã người dùng</div>
                  <div className="pVal">{currentUser.userId}</div>
                </div>
              </div>

              <div className="pRow">
                <div className="pIcon">
                  <Icon name="user" size={22} />
                </div>
                <div>
                  <div className="pLbl">Họ và tên</div>
                  <div className="pVal">{currentUser.fullName}</div>
                </div>
              </div>

              <div className="pRow">
                <div className="pIcon">👤</div>
                <div>
                  <div className="pLbl">Tên đăng nhập</div>
                  <div className="pVal">{currentUser.username}</div>
                </div>
              </div>

              <div className="pRow">
                <div className="pIcon">🔑</div>
                <div>
                  <div className="pLbl">Mật khẩu</div>
                  <div className="pVal">********</div>
                </div>
              </div>

              <div className="pRow">
                <div className="pIcon">💼</div>
                <div>
                  <div className="pLbl">Vai trò</div>
                  <div className="pVal">{currentUser.role}</div>
                </div>
              </div>

              <div className="pRow">
                <div className="pIcon">✉️</div>
                <div>
                  <div className="pLbl">Email</div>
                  <div className="pVal">{currentUser.email}</div>
                </div>
              </div>

              <div className="pRow">
                <div className="pIcon">📞</div>
                <div>
                  <div className="pLbl">Số điện thoại</div>
                  <div className="pVal">{currentUser.phone}</div>
                </div>
              </div>

              <div className="pRow">
                <div className="pIcon">✅</div>
                <div>
                  <div className="pLbl">Trạng thái</div>
                  <div className="pVal" style={{ color: "#2f7bd3" }}>
                    {currentUser.status}
                  </div>
                </div>
              </div>
            </div>

            <div className="profileActions">
              <button className="btn btnPrimary">Chỉnh sửa thông tin</button>

              {/* ✅ Nút Đổi mật khẩu mở modal */}
              <button className="btn" onClick={() => setOpenPw(true)}>
                Đổi mật khẩu
              </button>
            </div>
          </div>
        </div>

        {/* ✅ Modal nằm trong file, trước </div> ngoài cùng */}
        <ChangePasswordModal
          open={openPw}
          onClose={() => setOpenPw(false)}
          onSubmit={(payload) => console.log("change-password:", payload)}
        />
      </div>
    </div>
  );
}
