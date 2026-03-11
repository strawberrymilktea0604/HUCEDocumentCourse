import React, { useMemo, useState } from "react";
import TopBar from "../components/TopBar.jsx";
import SideNav from "../components/SideNav.jsx";
import "./StockIn.css";

// ---------- helpers ----------
function formatMoney(v) {
  if (v === null || v === undefined || Number.isNaN(Number(v))) return "0 đ";
  const n = Number(v);
  return n.toLocaleString("vi-VN") + " đ";
}
function formatNumber(v) {
  if (v === null || v === undefined || Number.isNaN(Number(v))) return "0";
  return Number(v).toLocaleString("vi-VN");
}

// ---------- modal shell ----------
function Modal({ title, onClose, children, width = 1180 }) {
  return (
    <div className="nmOverlay" onMouseDown={onClose}>
      <div
        className="nmModal"
        style={{ width }}
        onMouseDown={(e) => e.stopPropagation()}
      >
        <div className="nmModalHeader">
          <div className="nmModalTitle">{title}</div>
          <button className="nmClose" onClick={onClose} aria-label="close">
            ×
          </button>
        </div>
        <div className="nmModalBody">{children}</div>
      </div>
    </div>
  );
}

function ConfirmDelete({ onYes, onNo }) {
  return (
    <div className="confirmWrap">
      <div className="confirmTitle">Xóa yêu cầu nhập kho</div>
      <div className="confirmBtns">
        <button className="btnDanger" onClick={onYes}>
          Có
        </button>
        <button className="btnGhost" onClick={onNo}>
          Không
        </button>
      </div>
    </div>
  );
}

// ---------- page ----------
export default function StockIn() {
  // mock user giống topbar của bạn
  const user = { userId: "0203568", fullName: "Ngô Thị Quế Anh", role: "Quản lý" };

  const [tab, setTab] = useState("receipts"); // "requests" | "receipts"

  // filter/search (để UI đúng ảnh)
  const [search, setSearch] = useState("");
  const [statusFilter, setStatusFilter] = useState("Tất cả trạng thái");

  // ----- data mẫu theo ảnh -----
  const receipts = useMemo(
    () => [
      {
        code: "PN001",
        date: "30/11/2025",
        supplier: "Công ty Hạt điều BP",
        requestCode: "YCN001",
        total: 25000000,
        status: "Đã nhập kho",
        items: [
          {
            materialCode: "DI12",
            materialName: "Hạt điều Bình Phước",
            lot: "LO20252811",
            unit: "Kg",
            qty: 500,
            price: 50000,
            amount: 25000000,
          },
        ],
        createdAt: "28/11/2025",
        creator: "Nguyễn Tất Mạnh",
        confirmer: "Ngô Thị Quế Anh",
        note: "Đã nhập kho đầy đủ",
      },
    ],
    []
  );

  const requests = useMemo(
    () => [
      {
        code: "YCN001",
        date: "28/11/2025",
        creator: "Nguyễn Tất Mạnh",
        approver: "Ngô Thị Quế Anh",
        supplier: "Công ty Hạt Điều BP",
        status: "Đã duyệt",
        note: "Không có",
        total: 25000000,
        items: [
          { materialCode: "DI12", materialName: "Hạt điều Bình Phước", unit: "Kg", qty: 500, price: 50000, amount: 25000000 },
        ],
      },
      {
        code: "YCN002",
        date: "11/12/2025",
        creator: "Đinh Xuân Nam",
        approver: "Chưa duyệt",
        supplier: "Công ty Đường Biên Hòa",
        status: "Chờ duyệt",
        note: "Cần gấp cho đơn hàng tháng 12",
        total: 2000000,
        items: [
          { materialCode: "DI34", materialName: "Đường ăn kiêng", unit: "Kg", qty: 50, price: 40000, amount: 2000000 },
        ],
      },
    ],
    []
  );

  // ----- modals state -----
  const [openCreateReceipt, setOpenCreateReceipt] = useState(false);
  const [openReceiptDetail, setOpenReceiptDetail] = useState(null); // code
  const [openRequestDetail, setOpenRequestDetail] = useState(null); // code
  const [openEditRequest, setOpenEditRequest] = useState(null); // code
  const [confirmDeleteId, setConfirmDeleteId] = useState(null); // code

  // ----- create receipt form state -----
  const [crDate, setCrDate] = useState("12/06/2025");
  const [crSupplier, setCrSupplier] = useState("");
  const [crConfirmer, setCrConfirmer] = useState("");
  const [crLinkRequest, setCrLinkRequest] = useState("Không liên kết");
  const [crStatus, setCrStatus] = useState("Đang xử lý");
  const [crNote, setCrNote] = useState("");
  const [crLines, setCrLines] = useState([
    { material: "", lot: "LO123456", unit: "", qty: "", price: "" },
  ]);

  const crTotal = useMemo(() => {
    return crLines.reduce((sum, r) => {
      const qty = Number(String(r.qty).replaceAll(".", "").replaceAll(",", "")) || 0;
      const price = Number(String(r.price).replaceAll(".", "").replaceAll(",", "")) || 0;
      return sum + qty * price;
    }, 0);
  }, [crLines]);

  function addCrLine() {
    setCrLines((prev) => [...prev, { material: "", lot: "", unit: "", qty: "", price: "" }]);
  }
  function removeCrLine(idx) {
    setCrLines((prev) => prev.filter((_, i) => i !== idx));
  }
  function updateCrLine(idx, patch) {
    setCrLines((prev) => prev.map((r, i) => (i === idx ? { ...r, ...patch } : r)));
  }

  // ----- edit request state (YCN002) -----
  const [erDate, setErDate] = useState("11/12/2025");
  const [erRole, setErRole] = useState("Công ty đường Biên Hòa");
  const [erNote, setErNote] = useState("Cần gấp cho đơn hàng tháng 12");
  const [erLines, setErLines] = useState([
    { material: "Hạt điều", unit: "Kg", qty: "50", price: "40000" },
    { material: "", unit: "", qty: "", price: "" },
  ]);

  const erTotal = useMemo(() => {
    return erLines.reduce((sum, r) => {
      const qty = Number(String(r.qty).replaceAll(".", "").replaceAll(",", "")) || 0;
      const price = Number(String(r.price).replaceAll(".", "").replaceAll(",", "")) || 0;
      return sum + qty * price;
    }, 0);
  }, [erLines]);

  function addErLine() {
    setErLines((prev) => [...prev, { material: "", unit: "", qty: "", price: "" }]);
  }
  function removeErLine(idx) {
    setErLines((prev) => prev.filter((_, i) => i !== idx));
  }
  function updateErLine(idx, patch) {
    setErLines((prev) => prev.map((r, i) => (i === idx ? { ...r, ...patch } : r)));
  }

  // ----- stats (đúng ảnh) -----
  const statTotal = receipts.length;
  const statImported = receipts.filter((r) => r.status === "Đã nhập kho").length;
  const statProcessing = receipts.filter((r) => r.status === "Đang xử lý").length;
  const statValue = receipts.reduce((s, r) => s + r.total, 0);

  return (
    <div className="stockInPage">
      <TopBar user={user} bellCount={0} />

      <div className="stockInMain">
        <SideNav />

        <div className="stockInContent">
          <div className="stockPanel">
            <div className="stockTabs">
              <button
                className={`tabBtn ${tab === "requests" ? "active" : ""}`}
                onClick={() => setTab("requests")}
              >
                Quản lý yêu cầu nhập kho
              </button>
              <button
                className={`tabBtn ${tab === "receipts" ? "active" : ""}`}
                onClick={() => setTab("receipts")}
              >
                Quản lý nhập kho
              </button>

              {tab === "requests" && (
                <button className="topRightBtn" onClick={() => setOpenEditRequest("YCN002")}>
                  + Tạo yêu cầu nhập kho
                </button>
              )}
              {tab === "receipts" && (
                <button className="topRightBtn" onClick={() => setOpenCreateReceipt(true)}>
                  + Tạo phiếu nhập
                </button>
              )}
            </div>

            <div className="stockDivider" />

            {tab === "receipts" ? (
              <>
                {/* search + filter */}
                <div className="stockTools">
                  <div className="searchBox">
                    <span className="sIcon">🔍</span>
                    <input
                      value={search}
                      onChange={(e) => setSearch(e.target.value)}
                      placeholder="Tìm kiếm..."
                    />
                  </div>

                  <div className="rightTools">
                    <select
                      className="selectBox"
                      value={statusFilter}
                      onChange={(e) => setStatusFilter(e.target.value)}
                    >
                      <option>Tất cả trạng thái</option>
                      <option>Đã nhập kho</option>
                      <option>Đang xử lý</option>
                      <option>Đã hủy</option>
                    </select>
                  </div>
                </div>

                {/* stats */}
                <div className="statRow">
                  <div className="statCard">
                    <div className="statText">
                      <div className="statLabel">Tổng phiếu nhập</div>
                      <div className="statValue blue">{formatNumber(statTotal)}</div>
                    </div>
                    <div className="statIcon blueBox" />
                  </div>

                  <div className="statCard">
                    <div className="statText">
                      <div className="statLabel">Đã nhập kho</div>
                      <div className="statValue green">{formatNumber(statImported)}</div>
                    </div>
                    <div className="statIcon greenBox" />
                  </div>

                  <div className="statCard">
                    <div className="statText">
                      <div className="statLabel">Đang xử lý</div>
                      <div className="statValue orange">{formatNumber(statProcessing)}</div>
                    </div>
                    <div className="statIcon orangeBox" />
                  </div>

                  <div className="statCard">
                    <div className="statText">
                      <div className="statLabel">Tổng giá trị</div>
                      <div className="statValue blue">{formatMoney(statValue)}</div>
                    </div>
                    <div className="statIcon chartBox" />
                  </div>
                </div>

                {/* table */}
                <div className="tableWrap">
                  <table className="nmTable">
                    <thead>
                      <tr>
                        <th>Mã phiếu</th>
                        <th>Ngày nhập</th>
                        <th>Nhà cung cấp</th>
                        <th>Mã yêu cầu</th>
                        <th>Tổng giá trị</th>
                        <th>Trạng thái</th>
                        <th>Thao tác</th>
                      </tr>
                    </thead>
                    <tbody>
                      {receipts.map((r) => (
                        <tr key={r.code}>
                          <td>{r.code}</td>
                          <td>{r.date}</td>
                          <td>{r.supplier}</td>
                          <td>{r.requestCode}</td>
                          <td>{formatMoney(r.total)}</td>
                          <td>
                            <span className="statusBlue">{r.status}</span>
                          </td>
                          <td>
                            <div className="actionBtns">
                              <button
                                className="iconBtn eye"
                                title="Xem"
                                onClick={() => setOpenReceiptDetail(r.code)}
                              >
                                👁
                              </button>
                              <button className="iconBtn print" title="In">
                                🖨
                              </button>
                            </div>
                          </td>
                        </tr>
                      ))}
                      {receipts.length === 0 && (
                        <tr>
                          <td colSpan={7} className="emptyCell">
                            Chưa có phiếu nhập.
                          </td>
                        </tr>
                      )}
                    </tbody>
                  </table>
                </div>
              </>
            ) : (
              <>
                {/* REQUESTS TAB */}
                <div className="stockTools">
                  <div className="searchBox">
                    <span className="sIcon">🔍</span>
                    <input
                      value={search}
                      onChange={(e) => setSearch(e.target.value)}
                      placeholder="Tìm kiếm..."
                    />
                  </div>

                  <div className="rightTools">
                    <select
                      className="selectBox"
                      value={statusFilter}
                      onChange={(e) => setStatusFilter(e.target.value)}
                    >
                      <option>Tất cả trạng thái</option>
                      <option>Đã duyệt</option>
                      <option>Chờ duyệt</option>
                      <option>Từ chối</option>
                    </select>
                  </div>
                </div>

                <div className="tableWrap">
                  <table className="nmTable">
                    <thead>
                      <tr>
                        <th>Mã phiếu</th>
                        <th>Ngày lập</th>
                        <th>Người lập</th>
                        <th>Nhà cung cấp</th>
                        <th>Tổng giá trị</th>
                        <th>Trạng thái</th>
                        <th>Thao tác</th>
                      </tr>
                    </thead>
                    <tbody>
                      {requests.map((r) => (
                        <tr key={r.code}>
                          <td>{r.code}</td>
                          <td>{r.date}</td>
                          <td>{r.creator}</td>
                          <td>{r.supplier}</td>
                          <td>{formatMoney(r.total)}</td>
                          <td>
                            {r.status === "Đã duyệt" && <span className="statusBlue">Đã duyệt</span>}
                            {r.status === "Chờ duyệt" && <span className="statusOrange">Chờ duyệt</span>}
                            {r.status !== "Đã duyệt" && r.status !== "Chờ duyệt" && (
                              <span className="statusGray">{r.status}</span>
                            )}
                          </td>
                          <td>
                            <div className="actionBtns">
                              <button
                                className="iconBtn eye"
                                title="Xem"
                                onClick={() => setOpenRequestDetail(r.code)}
                              >
                                👁
                              </button>
                              <button
                                className="iconBtn edit"
                                title="Sửa"
                                onClick={() => setOpenEditRequest(r.code)}
                              >
                                ✏
                              </button>
                              <button
                                className="iconBtn trash"
                                title="Xóa"
                                onClick={() => setConfirmDeleteId(r.code)}
                              >
                                🗑
                              </button>
                            </div>
                          </td>
                        </tr>
                      ))}
                      {requests.length === 0 && (
                        <tr>
                          <td colSpan={7} className="emptyCell">
                            Chưa có yêu cầu nhập kho.
                          </td>
                        </tr>
                      )}
                    </tbody>
                  </table>
                </div>
              </>
            )}
          </div>
        </div>
      </div>

      {/* ---------- MODALS ---------- */}

      {/* 1) TẠO PHIẾU NHẬP KHO */}
      {openCreateReceipt && (
        <Modal title="Tạo phiếu nhập kho" onClose={() => setOpenCreateReceipt(false)} width={1280}>
          <div className="formGrid">
            <div className="field">
              <label>
                Ngày nhập <span className="req">*</span>
              </label>
              <div className="inputWithIcon">
                <input value={crDate} onChange={(e) => setCrDate(e.target.value)} />
                <span className="endIcon">📅</span>
              </div>
            </div>

            <div className="field">
              <label>Người lập</label>
              <input value="Ngô Thị Quế Anh" disabled />
            </div>

            <div className="field">
              <label>Người xác nhận</label>
              <input
                value={crConfirmer}
                onChange={(e) => setCrConfirmer(e.target.value)}
                placeholder="Nhập tên người xác nhận"
              />
            </div>

            <div className="field">
              <label>
                Nhà cung cấp <span className="req">*</span>
              </label>
              <select value={crSupplier} onChange={(e) => setCrSupplier(e.target.value)}>
                <option value="">Chọn nhà cung cấp</option>
                <option>Công ty Hạt điều BP</option>
                <option>Công ty Đường Biên Hòa</option>
                <option>Công ty Nuts VN</option>
              </select>
            </div>

            <div className="field">
              <label>Tổng giá trị dự kiến</label>
              <input value={formatMoney(crTotal)} disabled />
            </div>

            <div className="field">
              <label>Liên kết phiếu yêu cầu nhập</label>
              <select value={crLinkRequest} onChange={(e) => setCrLinkRequest(e.target.value)}>
                <option>Không liên kết</option>
                <option>YCN001</option>
                <option>YCN002</option>
              </select>
            </div>

            <div className="field span2">
              <label>Ghi chú</label>
              <textarea value={crNote} onChange={(e) => setCrNote(e.target.value)} />
            </div>

            <div className="field">
              <label>
                Trạng thái <span className="req">*</span>
              </label>
              <select value={crStatus} onChange={(e) => setCrStatus(e.target.value)}>
                <option>Đang xử lý</option>
                <option>Đã nhập kho</option>
                <option>Đã hủy</option>
              </select>
            </div>
          </div>

          <div className="sectionDivider" />

          <div className="sectionHead">
            <div className="sectionTitle">Danh sách nguyên liệu</div>
            <button className="btnPrimary" onClick={addCrLine}>
              + Thêm nguyên liệu
            </button>
          </div>

          {crLines.length === 0 ? (
            <div className="emptyHint">Chưa có nguyên liệu nào. Nhấn “Thêm nguyên liệu” để bắt đầu.</div>
          ) : (
            <div className="linesWrap">
              {crLines.map((row, idx) => {
                const qty = Number(String(row.qty).replaceAll(".", "").replaceAll(",", "")) || 0;
                const price = Number(String(row.price).replaceAll(".", "").replaceAll(",", "")) || 0;
                const amount = qty * price;

                return (
                  <div key={idx} className="lineRow">
                    <div className="lineGrid">
                      <div className="lineField">
                        <div className="lineLabel">Nguyên liệu</div>
                        <select
                          value={row.material}
                          onChange={(e) => updateCrLine(idx, { material: e.target.value })}
                        >
                          <option value="">Chọn</option>
                          <option>Hạt điều</option>
                          <option>Đường</option>
                          <option>Sữa</option>
                          <option>Bao bì</option>
                        </select>
                      </div>

                      <div className="lineField">
                        <div className="lineLabel">Mã lô</div>
                        <input
                          value={row.lot}
                          onChange={(e) => updateCrLine(idx, { lot: e.target.value })}
                        />
                      </div>

                      <div className="lineField">
                        <div className="lineLabel">Đơn vị</div>
                        <select
                          value={row.unit}
                          onChange={(e) => updateCrLine(idx, { unit: e.target.value })}
                        >
                          <option value="">Chọn</option>
                          <option>Kg</option>
                          <option>Lít</option>
                          <option>Chiếc</option>
                        </select>
                      </div>

                      <div className="lineField">
                        <div className="lineLabel">Số lượng</div>
                        <input
                          value={row.qty}
                          onChange={(e) => updateCrLine(idx, { qty: e.target.value })}
                        />
                      </div>

                      <div className="lineField">
                        <div className="lineLabel">Đơn giá</div>
                        <input
                          value={row.price}
                          onChange={(e) => updateCrLine(idx, { price: e.target.value })}
                        />
                      </div>

                      <div className="lineField">
                        <div className="lineLabel">Thành tiền</div>
                        <input value={formatMoney(amount)} disabled />
                      </div>

                      <button className="trashBtn" onClick={() => removeCrLine(idx)} title="Xóa dòng">
                        🗑
                      </button>
                    </div>
                  </div>
                );
              })}
            </div>
          )}

          <div className="sumBar">
            <div>Tổng số mặt hàng: {crLines.length}</div>
            <div>Tổng giá trị: {formatMoney(crTotal)}</div>
          </div>

          <div className="modalFooter">
            <button className="btnGhost" onClick={() => setOpenCreateReceipt(false)}>
              Hủy
            </button>
            <button className="btnPrimaryBig" onClick={() => setOpenCreateReceipt(false)}>
              Tạo phiếu
            </button>
          </div>
        </Modal>
      )}

      {/* 2) CHI TIẾT PHIẾU NHẬP PN001 */}
      {openReceiptDetail && (
        <Modal
          title={`Chi tiết phiếu nhập kho - ${openReceiptDetail}`}
          onClose={() => setOpenReceiptDetail(null)}
          width={1200}
        >
          {(() => {
            const r = receipts.find((x) => x.code === openReceiptDetail);
            if (!r) return null;

            return (
              <>
                <div className="detailGrid">
                  <div className="dBlock">
                    <div className="dLabel">Mã phiếu</div>
                    <div className="dValue">{r.code}</div>

                    <div className="dLabel">Người lập</div>
                    <div className="dValue">{r.creator}</div>

                    <div className="dLabel">Nhà cung cấp</div>
                    <div className="dValue">{r.supplier}</div>

                    <div className="dLabel">Ghi chú</div>
                    <div className="dValue">{r.note}</div>
                  </div>

                  <div className="dBlock">
                    <div className="dLabel">Ngày lập</div>
                    <div className="dValue">{r.createdAt}</div>

                    <div className="dLabel">Người xác nhận</div>
                    <div className="dValue">{r.confirmer}</div>

                    <div className="dLabel">Trạng thái</div>
                    <div className="dValue statusBlue">{r.status}</div>

                    <div className="dLabel">Liên kết phiếu yêu cầu</div>
                    <div className="dValue linkGreen">{r.requestCode}</div>

                    <div className="dLabel">Tổng giá trị</div>
                    <div className="dValue">{formatMoney(r.total)}</div>
                  </div>
                </div>

                <div className="sectionDivider" />

                <div className="sectionTitle">Danh sách nguyên liệu</div>

                <div className="tableWrap">
                  <table className="nmTable">
                    <thead>
                      <tr>
                        <th>Mã NVL</th>
                        <th>Tên nguyên liệu</th>
                        <th>Mã lô</th>
                        <th>Đơn vị</th>
                        <th>Số lượng</th>
                        <th>Đơn giá</th>
                        <th>Thành tiền</th>
                      </tr>
                    </thead>
                    <tbody>
                      {r.items.map((it, i) => (
                        <tr key={i}>
                          <td>{it.materialCode}</td>
                          <td>{it.materialName}</td>
                          <td>{it.lot}</td>
                          <td>{it.unit}</td>
                          <td>{formatNumber(it.qty)}</td>
                          <td>{formatMoney(it.price)}</td>
                          <td>{formatMoney(it.amount)}</td>
                        </tr>
                      ))}
                    </tbody>
                  </table>
                </div>

                <div className="modalFooter rightOnly">
                  <button className="btnPrimaryBig">In phiếu</button>
                </div>
              </>
            );
          })()}
        </Modal>
      )}

      {/* 3) SỬA YÊU CẦU NHẬP KHO - YCN002 (theo ảnh) */}
      {openEditRequest && (
        <Modal
          title={`Sửa phiếu yêu cầu nhập kho - ${openEditRequest}`}
          onClose={() => setOpenEditRequest(null)}
          width={1200}
        >
          <div className="formGrid">
            <div className="field">
              <label>
                Ngày lập <span className="req">*</span>
              </label>
              <div className="inputWithIcon">
                <input value={erDate} onChange={(e) => setErDate(e.target.value)} />
                <span className="endIcon">📅</span>
              </div>
            </div>

            <div className="field">
              <label>
                Người lập <span className="req">*</span>
              </label>
              <input value="Đinh Xuân Nam" disabled />
            </div>

            <div className="field">
              <label>Vai trò</label>
              <select value={erRole} onChange={(e) => setErRole(e.target.value)}>
                <option>Công ty đường Biên Hòa</option>
                <option>Công ty Hạt điều BP</option>
              </select>
            </div>

            <div className="field">
              <label>Tổng giá trị dự kiến</label>
              <input value={formatMoney(erTotal)} disabled />
            </div>

            <div className="field span2">
              <label>Ghi chú</label>
              <textarea value={erNote} onChange={(e) => setErNote(e.target.value)} />
            </div>
          </div>

          <div className="sectionDivider" />

          <div className="sectionHead">
            <div className="sectionTitle">Danh sách nguyên liệu</div>
            <button className="btnPrimary" onClick={addErLine}>
              + Thêm nguyên liệu
            </button>
          </div>

          <div className="linesWrap">
            {erLines.map((row, idx) => {
              const qty = Number(String(row.qty).replaceAll(".", "").replaceAll(",", "")) || 0;
              const price = Number(String(row.price).replaceAll(".", "").replaceAll(",", "")) || 0;
              const amount = qty * price;

              return (
                <div key={idx} className="lineRow">
                  <div className="lineGrid reqGrid">
                    <div className="lineField">
                      <div className="lineLabel">Nguyên liệu</div>
                      <select
                        value={row.material}
                        onChange={(e) => updateErLine(idx, { material: e.target.value })}
                      >
                        <option value="">Chọn</option>
                        <option>Hạt điều</option>
                        <option>Đường</option>
                      </select>
                    </div>

                    <div className="lineField">
                      <div className="lineLabel">Đơn vị</div>
                      <select
                        value={row.unit}
                        onChange={(e) => updateErLine(idx, { unit: e.target.value })}
                      >
                        <option value="">Chọn</option>
                        <option>Kg</option>
                        <option>Lít</option>
                      </select>
                    </div>

                    <div className="lineField">
                      <div className="lineLabel">Số lượng</div>
                      <input
                        value={row.qty}
                        onChange={(e) => updateErLine(idx, { qty: e.target.value })}
                      />
                    </div>

                    <div className="lineField">
                      <div className="lineLabel">Đơn giá</div>
                      <input
                        value={row.price}
                        onChange={(e) => updateErLine(idx, { price: e.target.value })}
                      />
                    </div>

                    <div className="lineField">
                      <div className="lineLabel">Thành tiền</div>
                      <input value={formatMoney(amount)} disabled />
                    </div>

                    <button className="trashBtn" onClick={() => removeErLine(idx)} title="Xóa dòng">
                      🗑
                    </button>
                  </div>
                </div>
              );
            })}
          </div>

          <div className="modalFooter">
            <button className="btnGhost" onClick={() => setOpenEditRequest(null)}>
              Hủy
            </button>
            <button className="btnPrimaryBig" onClick={() => setOpenEditRequest(null)}>
              Cập nhật
            </button>
          </div>
        </Modal>
      )}

      {/* 4) CHI TIẾT YÊU CẦU: YCN001 / YCN002 + (YCN002 có nút Duyệt/Từ chối) */}
      {openRequestDetail && (
        <Modal
          title={`Chi tiết phiếu yêu cầu - ${openRequestDetail}`}
          onClose={() => setOpenRequestDetail(null)}
          width={1200}
        >
          {(() => {
            const r = requests.find((x) => x.code === openRequestDetail);
            if (!r) return null;

            return (
              <>
                <div className="detailGrid">
                  <div className="dBlock">
                    <div className="dLabel">Mã phiếu</div>
                    <div className="dValue">{r.code}</div>

                    <div className="dLabel">Người lập</div>
                    <div className="dValue">{r.creator}</div>

                    <div className="dLabel">Nhà cung cấp</div>
                    <div className="dValue">{r.supplier}</div>

                    <div className="dLabel">Ghi chú</div>
                    <div className="dValue">{r.note}</div>
                  </div>

                  <div className="dBlock">
                    <div className="dLabel">Ngày lập</div>
                    <div className="dValue">{r.date}</div>

                    <div className="dLabel">Người duyệt</div>
                    <div className="dValue">{r.approver}</div>

                    <div className="dLabel">Trạng thái</div>
                    <div className="dValue">
                      {r.status === "Đã duyệt" && <span className="statusBlue">Đã duyệt</span>}
                      {r.status === "Chờ duyệt" && <span className="statusOrange">Chờ duyệt</span>}
                      {r.status !== "Đã duyệt" && r.status !== "Chờ duyệt" && (
                        <span className="statusGray">{r.status}</span>
                      )}
                    </div>
                  </div>
                </div>

                <div className="sectionDivider" />

                <div className="sectionTitle">Danh sách nguyên liệu</div>

                <div className="tableWrap">
                  <table className="nmTable">
                    <thead>
                      <tr>
                        <th>Mã NVL</th>
                        <th>Tên nguyên liệu</th>
                        <th>Đơn vị</th>
                        <th>Số lượng</th>
                        <th>Đơn giá</th>
                        <th>Thành tiền</th>
                      </tr>
                    </thead>
                    <tbody>
                      {r.items.map((it, i) => (
                        <tr key={i}>
                          <td>{it.materialCode}</td>
                          <td>{it.materialName}</td>
                          <td>{it.unit}</td>
                          <td>{formatNumber(it.qty)}</td>
                          <td>{formatMoney(it.price)}</td>
                          <td>{formatMoney(it.amount)}</td>
                        </tr>
                      ))}
                      <tr>
                        <td colSpan={5} style={{ textAlign: "right", fontWeight: 500 }}>
                          Tổng cộng:
                        </td>
                        <td style={{ fontWeight: 600 }}>{formatMoney(r.total)}</td>
                      </tr>
                    </tbody>
                  </table>
                </div>

                {r.status === "Chờ duyệt" ? (
                  <div className="modalFooter">
                    <button className="btnGhost" onClick={() => setOpenRequestDetail(null)}>
                      Từ chối
                    </button>
                    <button className="btnPrimaryBig" onClick={() => setOpenRequestDetail(null)}>
                      Duyệt
                    </button>
                  </div>
                ) : (
                  <div className="modalFooter rightOnly">
                    <button className="btnGhost" onClick={() => setOpenRequestDetail(null)}>
                      Đóng
                    </button>
                  </div>
                )}
              </>
            );
          })()}
        </Modal>
      )}

      {/* 5) MODAL XÁC NHẬN XÓA (Có/Không) */}
      {confirmDeleteId && (
        <div className="nmOverlay" onMouseDown={() => setConfirmDeleteId(null)}>
          <div className="confirmModal" onMouseDown={(e) => e.stopPropagation()}>
            <ConfirmDelete
              onYes={() => setConfirmDeleteId(null)}
              onNo={() => setConfirmDeleteId(null)}
            />
          </div>
        </div>
      )}
    </div>
  );
}
