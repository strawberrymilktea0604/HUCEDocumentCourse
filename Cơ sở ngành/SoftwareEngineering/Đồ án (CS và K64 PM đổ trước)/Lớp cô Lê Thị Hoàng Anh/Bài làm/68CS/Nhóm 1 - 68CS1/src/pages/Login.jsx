import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import { NutMilkLogo, Icon } from "../components/Icons.jsx";

export default function Login() {
  const nav = useNavigate();
  const [showPass, setShowPass] = useState(false);
  const [emp, setEmp] = useState("");
  const [pass, setPass] = useState("");

  return (
    <div style={{ minHeight: "100vh", background: "var(--bg)" }}>
      {/* Top */}
      <div style={{ height: 86, display: "flex", alignItems: "center", justifyContent: "space-between", padding: "0 28px" }}>
        <div style={{ display: "flex", alignItems: "center", gap: 10 }}>
          <NutMilkLogo size={44} />
          <div style={{ fontWeight: 800, color: "#2a78d8" }}>NutMilk</div>
        </div>
        <div style={{ fontWeight: 900, color: "#2a78d8", fontSize: 24 }}>ĐĂNG NHẬP</div>
      </div>

      {/* Center card */}
      <div style={{ display: "grid", placeItems: "center", paddingTop: 120 }}>
        <div className="softCard" style={{ width: 520, padding: "34px 38px" }}>
          <div style={{ textAlign: "center", fontWeight: 900, fontSize: 26, color: "#2a78d8" }}>Chào mừng trở lại!</div>
          <div style={{ textAlign: "center", marginTop: 10, color: "rgba(32,48,70,.65)", fontWeight: 500 }}>
            Vui lòng đăng nhập để tiếp tục
          </div>

          <div style={{ marginTop: 26, display: "flex", flexDirection: "column", gap: 18 }}>
            <div style={{ position: "relative" }}>
              <span style={{ position: "absolute", left: 14, top: "50%", transform: "translateY(-50%)", color: "rgba(32,48,70,.65)" }}>
                <Icon name="user" size={20} />
              </span>
              <input
                className="input"
                style={{ paddingLeft: 44 }}
                placeholder="Mã nhân viên"
                value={emp}
                onChange={(e) => setEmp(e.target.value)}
              />
            </div>

            <div style={{ position: "relative" }}>
              <span style={{ position: "absolute", left: 14, top: "50%", transform: "translateY(-50%)", color: "rgba(32,48,70,.65)" }}>
                🔒
              </span>
              <input
                className="input"
                style={{ paddingLeft: 44, paddingRight: 44 }}
                placeholder="Mật khẩu"
                type={showPass ? "text" : "password"}
                value={pass}
                onChange={(e) => setPass(e.target.value)}
              />
              <button
                onClick={() => setShowPass((s) => !s)}
                style={{
                  position: "absolute",
                  right: 10,
                  top: "50%",
                  transform: "translateY(-50%)",
                  width: 36,
                  height: 36,
                  borderRadius: 12,
                  border: "1px solid rgba(32,48,70,.15)",
                  background: "#fff",
                  cursor: "pointer",
                }}
                aria-label="Hiện mật khẩu"
              >
                <Icon name="eye" size={18} />
              </button>
            </div>

            <button
              className="btn btnPrimary"
              style={{ height: 52, borderRadius: 16, fontSize: 18 }}
              onClick={() => {
                // demo login
                localStorage.setItem("authed", "1");
                nav("/dashboard");
              }}
            >
              Đăng nhập
            </button>

            <div style={{ textAlign: "center", color: "#2a78d8", fontWeight: 700, marginTop: 4, cursor: "pointer" }}>
              Quên mật khẩu?
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
