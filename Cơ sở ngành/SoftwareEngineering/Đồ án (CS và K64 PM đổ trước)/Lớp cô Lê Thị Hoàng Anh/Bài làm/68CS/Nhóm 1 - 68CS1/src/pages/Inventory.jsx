import React, { useMemo, useState } from "react";
import TopBar from "../components/TopBar.jsx";
import SideNav from "../components/SideNav.jsx";
import { currentUser } from "../data/mock.js";

/* ====== Icons (inline để khỏi phụ thuộc) ====== */
function IcoSearch({ size = 18 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path
        d="M10.5 18.5a8 8 0 1 1 0-16 8 8 0 0 1 0 16Z"
        stroke="currentColor"
        strokeWidth="2"
      />
      <path
        d="M16.5 16.5 21 21"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
      />
    </svg>
  );
}

function IcoPlus({ size = 16 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path
        d="M12 5v14M5 12h14"
        stroke="currentColor"
        strokeWidth="2.4"
        strokeLinecap="round"
      />
    </svg>
  );
}

function IcoEye({ size = 18 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path
        d="M2 12s3.5-7 10-7 10 7 10 7-3.5 7-10 7S2 12 2 12Z"
        stroke="currentColor"
        strokeWidth="2"
      />
      <path
        d="M12 15a3 3 0 1 0 0-6 3 3 0 0 0 0 6Z"
        stroke="currentColor"
        strokeWidth="2"
      />
    </svg>
  );
}

function IcoClose({ size = 22 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path
        d="M6 6l12 12M18 6 6 18"
        stroke="currentColor"
        strokeWidth="2.4"
        strokeLinecap="round"
      />
    </svg>
  );
}

function IcoCalendar({ size = 18 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 24 24" fill="none">
      <path
        d="M7 4v2M17 4v2"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
      />
      <path
        d="M4.5 9h15"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
      />
      <path
        d="M6.5 6h11A2.5 2.5 0 0 1 20 8.5v10A2.5 2.5 0 0 1 17.5 21h-11A2.5 2.5 0 0 1 4 18.5v-10A2.5 2.5 0 0 1 6.5 6Z"
        stroke="currentColor"
        strokeWidth="2"
      />
    </svg>
  );
}

/* ====== Modal: Tạo phiếu kiểm kê mới (full màn hình như ảnh) ====== */
function CreateInventoryModal({ open, onClose, onSubmit, lots }) {
  const [title, setTitle] = useState("");
  const [desc, setDesc] = useState("");
  const [date, setDate] = useState("");
  const [checked, setChecked] = useState(() => ({}));

  if (!open) return null;

  const toggle = (id) =>
    setChecked((p) => ({
      ...p,
      [id]: !p[id],
    }));

  const handleSubmit = () => {
    const selected = lots.filter((x) => checked[x.id]);
    onSubmit?.({
      title,
      desc,
      date,
      selectedLots: selected,
    });
    onClose?.();
  };

  return (
    <div className="invModalFull">
      <div className="invModalHeader">
        <div className="invModalTitle">Tạo phiếu kiểm kê mới</div>
        <button className="invX" onClick={onClose} aria-label="Close">
          <IcoClose />
        </button>
      </div>
      <div className="invModalLine" />

      <div className="invModalBody">
        <div className="invModalSection">Thông tin chung</div>

        <div className="invField">
          <div className="invLbl">
            Tiêu đề <span className="invReq">*</span>
          </div>
          <input
            className="invInput"
            placeholder="Nhập tiêu đề phiếu kiểm kê"
            value={title}
            onChange={(e) => setTitle(e.target.value)}
          />
        </div>

        <div className="invField">
          <div className="invLbl">Mô tả</div>
          <input
            className="invInput"
            placeholder="Nhập mô tả (nếu có)"
            value={desc}
            onChange={(e) => setDesc(e.target.value)}
          />
        </div>

        <div className="invField">
          <div className="invLbl">
            Ngày dự kiến <span className="invReq">*</span>
          </div>

          <div className="invDateWrap">
            <input
              className="invInput invDateInput"
              placeholder="dd/mm/yyyy"
              value={date}
              onChange={(e) => setDate(e.target.value)}
            />
            <div className="invDateIco">
              <IcoCalendar />
            </div>
          </div>
        </div>

        <div className="invModalPick">Chọn lô nguyên liệu cần kiểm kê</div>

        <div className="invLotTableWrap">
          <table className="invLotTable">
            <thead>
              <tr>
                <th className="invChkTh">
                  <input type="checkbox" disabled />
                </th>
                <th>Mã lô</th>
                <th>Nguyên liệu</th>
                <th>Vị trí</th>
                <th>Số sổ sách</th>
                <th>Số thực tế</th>
                <th>Ghi chú</th>
              </tr>
            </thead>
            <tbody>
              {lots.map((r) => (
                <tr key={r.id}>
                  <td className="invChkTd">
                    <input
                      type="checkbox"
                      checked={!!checked[r.id]}
                      onChange={() => toggle(r.id)}
                    />
                  </td>
                  <td>{r.code}</td>
                  <td>{r.material}</td>
                  <td>{r.pos}</td>
                  <td>{r.bookQty}</td>
                  <td />
                  <td />
                </tr>
              ))}
            </tbody>
          </table>
        </div>

        <div className="invModalActions">
          <button className="btn" onClick={onClose}>
            Hủy
          </button>
          <button className="btn btnPrimary" onClick={handleSubmit}>
            Tạo phiếu
          </button>
        </div>
      </div>
    </div>
  );
}

/* ====== Page ====== */
export default function Inventory() {
  const [tab, setTab] = useState("list"); // list | report
  const [q, setQ] = useState("");
  const [openCreate, setOpenCreate] = useState(false);

  const tickets = useMemo(
    () => [
      {
        id: "PKK2811",
        code: "PKK2811",
        date: "28/11/2025",
        maker: "Ngô Thị Quế Anh",
        title: "Kiểm kê định kỳ",
        desc: "Kiểm kê toàn bộ nguyên liệu\ntrong kho theo kế hoạch",
        doer: "Nguyễn Tất Mạnh",
        status: "Đã duyệt",
      },
      {
        id: "PKK1112",
        code: "PKK1112",
        date: "11/12/2025",
        maker: "Ngô Thị Quế Anh",
        title: "Kiểm kê đột xuất",
        desc: "kiểm kê tình trạng NVL trong\nkho lạnh sau sự cố mất điện",
        doer: "Nguyễn Tất Mạnh",
        status: "Chờ duyệt",
      },
      {
        id: "PKK1812",
        code: "PKK1812",
        date: "18/12/2025",
        maker: "Ngô Thị Quế Anh",
        title: "Kiểm kê bao bì T12",
        desc: "Kiểm kê số lượng chai lọ và\nvật liệu đóng gói",
        doer: "Đinh Xuân Nam",
        status: "Đang kiểm kê",
      },
    ],
    []
  );

  const filteredTickets = useMemo(() => {
    const k = q.trim().toLowerCase();
    if (!k) return tickets;
    return tickets.filter((x) => {
      const blob = `${x.code} ${x.maker} ${x.title} ${x.desc} ${x.doer} ${x.status}`.toLowerCase();
      return blob.includes(k);
    });
  }, [q, tickets]);

  const stockReport = useMemo(
    () => [
      { lot: "LO20241123", material: "Hạt điều", pos: "Hàng 2 - Kệ A", qty: "250 Kg", stt: "Còn hàng" },
      { lot: "LO20241124", material: "Hạt điều", pos: "Hàng 2 - Kệ A", qty: "250 Kg", stt: "Còn hàng" },
      { lot: "LO20241125", material: "Đường", pos: "Hàng 2 - Kệ B", qty: "50 Kg", stt: "Còn hàng" },
    ],
    []
  );

  const lotsToPick = useMemo(
    () => [
      { id: "LO112233", code: "LO112233", material: "Hạt điều", pos: "Hàng 2 - Kệ A", bookQty: "250 Kg" },
      { id: "LO112253", code: "LO112253", material: "Hạt điều", pos: "Hàng 3 - Kệ A", bookQty: "150 Kg" },
      { id: "LO112254", code: "LO112254", material: "Đường", pos: "Hàng 2 - Kệ B", bookQty: "100 Kg" },
      { id: "LO113253", code: "LO113253", material: "Đường", pos: "Hàng 3 - Kệ B", bookQty: "50 Kg" },
    ],
    []
  );

  return (
    <div>
      <TopBar user={currentUser} bellCount={0} />

      <div className="invWrap">
        <SideNav />

        <div className="invMain">
          <div className="invCard">
            <div className="invTopRow">
              <div className="invTabs">
                <button
                  className={"invTab" + (tab === "list" ? " active" : "")}
                  onClick={() => setTab("list")}
                >
                  Danh sách phiếu kiểm kê
                </button>
                <button
                  className={"invTab" + (tab === "report" ? " active" : "")}
                  onClick={() => setTab("report")}
                >
                  Thống kê &amp; Báo cáo
                </button>
              </div>

              {tab === "list" && (
                <button className="invCreateBtn" onClick={() => setOpenCreate(true)}>
                  <span className="invCreatePlus">
                    <IcoPlus />
                  </span>
                  Tạo phiếu kiểm kê
                </button>
              )}
            </div>

            <div className="invDivider" />

            {tab === "list" ? (
              <div className="invBody">
                <div className="invSearch">
                  <span className="invSearchIco">
                    <IcoSearch />
                  </span>
                  <input
                    value={q}
                    onChange={(e) => setQ(e.target.value)}
                    placeholder="Tìm kiếm..."
                  />
                </div>

                <div className="invTableBox">
                  <table className="invTable">
                    <thead>
                      <tr>
                        <th style={{ width: 90 }}>Mã phiếu</th>
                        <th style={{ width: 120 }}>Ngày kiểm kê</th>
                        <th style={{ width: 130 }}>Người lập</th>
                        <th>Tiêu đề</th>
                        <th style={{ width: 150 }}>Người thực hiện</th>
                        <th style={{ width: 120 }}>Trạng thái</th>
                        <th style={{ width: 90, textAlign: "center" }}>Thao tác</th>
                      </tr>
                    </thead>
                    <tbody>
                      {filteredTickets.map((r) => (
                        <tr key={r.id}>
                          <td>{r.code}</td>
                          <td>{r.date}</td>
                          <td className="invMaker">{r.maker}</td>
                          <td>
                            <div className="invTitle">{r.title}</div>
                            <div className="invDesc">{r.desc}</div>
                          </td>
                          <td>{r.doer}</td>
                          <td>
                            <span
                              className={
                                "invStatus " +
                                (r.status === "Đã duyệt"
                                  ? "stBlue"
                                  : r.status === "Chờ duyệt"
                                  ? "stOrange"
                                  : "stGreen")
                              }
                            >
                              {r.status}
                            </span>
                          </td>
                          <td style={{ textAlign: "center" }}>
                            <button className="invEyeBtn" title="Xem">
                              <IcoEye />
                            </button>
                          </td>
                        </tr>
                      ))}
                    </tbody>
                  </table>
                </div>
              </div>
            ) : (
              <div className="invBody invReport">
                <div className="invSection">Báo cáo tồn kho hiện tại</div>

                <div className="invTableBox">
                  <table className="invTable invTableSmall">
                    <thead>
                      <tr>
                        <th style={{ width: 130 }}>Mã lô</th>
                        <th>Nguyên liệu</th>
                        <th>Vị trí</th>
                        <th style={{ width: 140 }}>Tồn kho</th>
                        <th style={{ width: 140 }}>Trạng thái</th>
                      </tr>
                    </thead>
                    <tbody>
                      {stockReport.map((r) => (
                        <tr key={r.lot}>
                          <td>{r.lot}</td>
                          <td>{r.material}</td>
                          <td>{r.pos}</td>
                          <td>{r.qty}</td>
                          <td>{r.stt}</td>
                        </tr>
                      ))}
                    </tbody>
                  </table>
                </div>

                <div className="invSection" style={{ marginTop: 28 }}>
                  Phân tích chênh lệch
                </div>

                <div className="invDiffCard">
                  <div className="invDiffHead">
                    <div>
                      <div className="invDiffName">Kiểm kê định kỳ tháng 12</div>
                      <div className="invDiffDate">10/12/2025</div>
                    </div>
                    <div className="invDiffCode">PKK2024221</div>
                  </div>

                  <div className="invDiffBars">
                    <div className="invDiffBar red">
                      <div>Hạt điều</div>
                      <div className="invDiffVal redTxt">-2 Kg</div>
                    </div>
                    <div className="invDiffBar green">
                      <div>Hạt điều</div>
                      <div className="invDiffVal greenTxt">0 Kg</div>
                    </div>
                    <div className="invDiffBar blue">
                      <div>Đường</div>
                      <div className="invDiffVal blueTxt">+5 Kg</div>
                    </div>
                  </div>
                </div>
              </div>
            )}
          </div>
        </div>
      </div>

      <CreateInventoryModal
        open={openCreate}
        onClose={() => setOpenCreate(false)}
        onSubmit={(payload) => console.log("create-inventory:", payload)}
        lots={lotsToPick}
      />
    </div>
  );
}
