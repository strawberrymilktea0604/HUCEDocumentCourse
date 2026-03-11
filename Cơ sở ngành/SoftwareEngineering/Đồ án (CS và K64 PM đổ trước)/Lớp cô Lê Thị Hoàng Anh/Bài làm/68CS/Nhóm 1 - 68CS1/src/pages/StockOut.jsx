import React, { useMemo, useState } from "react";
import "./StockOut.css";

/* ====== ICONS (inline SVG) ====== */
function IconEye({ size = 16 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path
        d="M2 12s3.5-7 10-7 10 7 10 7-3.5 7-10 7S2 12 2 12Z"
        stroke="#1F69A6"
        strokeWidth="2"
      />
      <circle cx="12" cy="12" r="3" stroke="#1F69A6" strokeWidth="2" />
    </svg>
  );
}

function IconPrint({ size = 16 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path
        d="M7 8V3h10v5"
        stroke="#5DAC62"
        strokeWidth="2"
        strokeLinejoin="round"
      />
      <path
        d="M7 17h10v4H7v-4Z"
        stroke="#5DAC62"
        strokeWidth="2"
        strokeLinejoin="round"
      />
      <path
        d="M6 10h12a3 3 0 0 1 3 3v4h-4"
        stroke="#5DAC62"
        strokeWidth="2"
        strokeLinejoin="round"
      />
      <path
        d="M2 17v-4a3 3 0 0 1 3-3h1"
        stroke="#5DAC62"
        strokeWidth="2"
        strokeLinejoin="round"
      />
    </svg>
  );
}

function IconBars({ size = 22 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path d="M4 20V10" stroke="#1F69A6" strokeWidth="2" />
      <path d="M10 20V4" stroke="#1F69A6" strokeWidth="2" />
      <path d="M16 20V14" stroke="#1F69A6" strokeWidth="2" />
      <path d="M22 20V8" stroke="#1F69A6" strokeWidth="2" />
    </svg>
  );
}

/* ====== PAGE ====== */
export default function StockOut() {
  // mock đúng như ảnh bạn gửi
  const rows = useMemo(
    () => [
      {
        code: "PX001",
        date: "12/12/2025",
        receiver: "Lê Việt Anh",
        request: "YCX001",
        total: "3.350.000 đ",
        status: "Đã xuất kho",
        statusClass: "blue",
      },
      {
        code: "PX002",
        date: "15/12/2025",
        receiver: "Lê Đỗ Việt Tùng",
        request: "YCX002",
        total: "0 đ",
        status: "Đang xử lý",
        statusClass: "yellow",
      },
    ],
    []
  );

  const [status, setStatus] = useState("Tất cả trạng thái");

  return (
    <div className="soScreen">
      {/* TOP BAR */}
      <div className="soTopbar">
        <div className="soLogo" aria-hidden />
        <div className="soBrand">
          <div className="soBrandTitle">NutMilk - Quản lý Kho</div>
          <div className="soBrandYear">Năm 2025</div>
        </div>

        <div className="soBell">
          <div className="soBellDot">0</div>
        </div>

        <div className="soGlobalSearch">
          <span className="soSearchIcon" />
          <div className="soSearchPlaceholder">Tìm kiếm...</div>
        </div>

        <div className="soUserBox">
          <div className="soUserIcon" />
          <div className="soUserText">
            <div className="soUserLine1">0203568 - Ngô Thị Quế Anh</div>
            <div className="soUserLine2">Quản lý</div>
          </div>
        </div>
      </div>

      {/* ✅ ĐƯỜNG KẺ: đã hạ xuống + z-index/pointer-events */}
      <div className="soTopLine" />

      {/* SIDE NAV */}
      <div className="soSide">
        <div className="soSideItem">
          <span className="soSideIco home" /> Trang chủ
        </div>
        <div className="soSideItem">
          <span className="soSideIco user" /> Thông tin cá nhân
        </div>
        <div className="soSideItem">
          <span className="soSideIco group" /> Quản lý người dùng
        </div>

        <div className="soSideItem active">
          <span className="soSideIco out" /> Xuất kho
        </div>

        <div className="soSideItem">
          <span className="soSideIco in" /> Nhập kho
        </div>

        <div className="soSideItem">
          <span className="soSideIco doc" /> Nguyên vật liệu
        </div>
        <div className="soSideItem">
          <span className="soSideIco supplier" /> Nhà cung cấp
        </div>
        <div className="soSideItem">
          <span className="soSideIco check" /> Kiểm kê
        </div>
      </div>

      {/* MAIN PANEL */}
      <div className="soPanel">
        <div className="soTabLeft">Quản lý yêu cầu xuất kho</div>
        <div className="soTabActive">Quản lý xuất kho</div>
        <div className="soTabUnderline" />
        <div className="soPanelDivider" />

        {/* Search in panel */}
        <div className="soSearchBox">
          <span className="soSearchMini" />
          <div className="soSearchText">Tìm kiếm...</div>
        </div>

        {/* Status filter */}
        <div className="soFilterWrap">
          <select
            className="soFilterSelect"
            value={status}
            onChange={(e) => setStatus(e.target.value)}
          >
            <option>Tất cả trạng thái</option>
            <option>Đã xuất kho</option>
            <option>Đang xử lý</option>
          </select>
        </div>

        {/* Create button */}
        <button className="soCreateBtn" type="button">
          <span className="soPlus">+</span>
          Tạo phiếu xuất
        </button>

        {/* Summary cards */}
        <div className="soCard c1">
          <div className="soCardLabel">Tổng phiếu xuất</div>
          <div className="soCardValue blue">2</div>
          <div className="soCardIcon blue" aria-hidden />
        </div>

        <div className="soCard c2">
          <div className="soCardLabel">Đã xuất kho</div>
          <div className="soCardValue green">1</div>
          <div className="soCardIcon green" aria-hidden />
        </div>

        <div className="soCard c3">
          <div className="soCardLabel">Đang xử lý</div>
          <div className="soCardValue yellow">1</div>
          <div className="soCardIcon yellow" aria-hidden />
        </div>

        <div className="soCard c4">
          <div className="soCardLabel">Tổng giá trị</div>
          <div className="soCardValueMoney">3.4 M đ</div>
          <div className="soBars">
            <IconBars size={22} />
          </div>
        </div>

        {/* Table header */}
        <div className="soTableHead">
          <div className="col cCode">Mã phiếu</div>
          <div className="col cDate">Ngày xuất</div>
          <div className="col cReceiver">Người nhận</div>
          <div className="col cReq">Mã yêu cầu</div>
          <div className="col cTotal">Tổng giá trị</div>
          <div className="col cStatus">Trạng thái</div>
          <div className="col cAction">Thao tác</div>
        </div>

        {/* Rows */}
        {rows
          .filter((r) =>
            status === "Tất cả trạng thái" ? true : r.status === status
          )
          .map((r, idx) => (
            <div key={r.code} className="soRow" style={{ top: 344 + idx * 40 }}>
              <div className="col cCode">{r.code}</div>
              <div className="col cDate">{r.date}</div>
              <div className="col cReceiver">{r.receiver}</div>
              <div className="col cReq">{r.request}</div>
              <div className="col cTotal">{r.total}</div>
              <div className={"col cStatus " + r.statusClass}>{r.status}</div>
              <div className="col cAction">
                <button className="soIconBtn" title="Xem" type="button">
                  <IconEye />
                </button>
                <button className="soIconBtn" title="In" type="button">
                  <IconPrint />
                </button>
              </div>
            </div>
          ))}
      </div>
    </div>
  );
}
