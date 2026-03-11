import React from "react";
import TopBar from "../components/TopBar.jsx";
import { currentUser } from "../data/mock.js";

export default function Placeholder({ title }) {
  return (
    <div>
      <TopBar user={currentUser} bellCount={0} />
      <div style={{ padding: 24 }}>
        <div className="card" style={{ padding: 22 }}>
          <div style={{ fontWeight: 900, fontSize: 24 }}>{title}</div>
          <div style={{ marginTop: 10, color: "rgba(32,48,70,.7)", fontWeight: 600 }}>
            Trang này đang là khung chờ. Bạn gửi tiếp ảnh màn này, mình sẽ dựng đúng 100% theo thiết kế.
          </div>
        </div>
      </div>
    </div>
  );
}
