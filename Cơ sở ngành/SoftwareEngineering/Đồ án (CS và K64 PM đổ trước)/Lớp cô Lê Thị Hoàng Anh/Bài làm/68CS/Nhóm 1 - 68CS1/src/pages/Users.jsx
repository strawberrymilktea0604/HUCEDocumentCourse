import React, { useEffect, useMemo, useState } from "react";
import TopBar from "../components/TopBar.jsx";
import SideNav from "../components/SideNav.jsx";
import { currentUser, mockUsers } from "../data/mock.js";
import {
  UserCreateModal,
  UserEditModal,
  ConfirmDeleteDialog,
} from "../components/UserModals.jsx";

const STORAGE_KEY = "nutmilk_users_v1";

export default function Users() {
  const [users, setUsers] = useState(() => {
    const raw = localStorage.getItem(STORAGE_KEY);
    if (raw) {
      try {
        return JSON.parse(raw);
      } catch {
        return mockUsers;
      }
    }
    return mockUsers;
  });

  useEffect(() => {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(users));
  }, [users]);

  const [q, setQ] = useState("");
  const [openCreate, setOpenCreate] = useState(false);
  const [openEdit, setOpenEdit] = useState(false);
  const [editing, setEditing] = useState(null);
  const [openDel, setOpenDel] = useState(false);
  const [deleting, setDeleting] = useState(null);

  const filtered = useMemo(() => {
    const s = q.trim().toLowerCase();
    if (!s) return users;
    return users.filter((u) => {
      const blob = [
        u.userId,
        u.fullName,
        u.username,
        u.role,
        u.email,
        u.phone,
        u.status,
      ]
        .join(" ")
        .toLowerCase();
      return blob.includes(s);
    });
  }, [users, q]);

  const onCreate = (payload) => {
    const exists = users.some((u) => u.userId === payload.userId);
    if (exists) {
      alert("Mã người dùng đã tồn tại.");
      return;
    }
    setUsers((prev) => [payload, ...prev]);
  };

  const onEdit = (payload) => {
    setUsers((prev) => prev.map((u) => (u.userId === payload.userId ? payload : u)));
  };

  const onDelete = () => {
    if (!deleting) return;
    setUsers((prev) => prev.filter((u) => u.userId !== deleting.userId));
    setDeleting(null);
    setOpenDel(false);
  };

  return (
    <div>
      <TopBar user={currentUser} bellCount={0} />

      <div className="umWrap">
        <SideNav />

        <div className="umCard">
          <div className="umHeader">
            <div className="umTitle">Quản lý người dùng</div>

            <div className="umSearch">
              <span className="umSearchIcon">🔍</span>
              <input
                value={q}
                onChange={(e) => setQ(e.target.value)}
                placeholder="Tìm kiếm..."
              />
            </div>

            <button className="umAddBtn" onClick={() => setOpenCreate(true)}>
              + Thêm người dùng
            </button>
          </div>

          <div className="umTableWrap">
            <table className="umTable">
              <thead>
                <tr>
                  <th>Mã người dùng</th>
                  <th>Họ và tên</th>
                  <th>Tên đăng nhập</th>
                  <th>Vai trò</th>
                  <th>Email</th>
                  <th>Số điện thoại</th>
                  <th>Trạng thái</th>
                  <th>Thao tác</th>
                </tr>
              </thead>
              <tbody>
                {filtered.map((u) => (
                  <tr key={u.userId}>
                    <td>{u.userId}</td>
                    <td>{u.fullName}</td>
                    <td>{u.username}</td>
                    <td>{u.role}</td>
                    <td>{u.email}</td>
                    <td>{u.phone}</td>
                    <td>
                      <span
                        className={
                          u.status === "Hoạt động" ? "umStatusActive" : "umStatusInactive"
                        }
                      >
                        {u.status}
                      </span>
                    </td>
                    <td>
                      <div className="umActions">
                        <button
                          className="umIconBtn umEdit"
                          title="Sửa"
                          onClick={() => {
                            setEditing(u);
                            setOpenEdit(true);
                          }}
                        >
                          ✎
                        </button>
                        <button
                          className="umIconBtn umTrash"
                          title="Xóa"
                          onClick={() => {
                            setDeleting(u);
                            setOpenDel(true);
                          }}
                        >
                          🗑
                        </button>
                      </div>
                    </td>
                  </tr>
                ))}

                {filtered.length === 0 && (
                  <tr>
                    <td colSpan={8} className="umEmpty">
                      Không có dữ liệu
                    </td>
                  </tr>
                )}
              </tbody>
            </table>
          </div>
        </div>
      </div>

      <UserCreateModal
        open={openCreate}
        onClose={() => setOpenCreate(false)}
        onSubmit={onCreate}
      />

      <UserEditModal
        open={openEdit}
        onClose={() => setOpenEdit(false)}
        user={editing}
        onSubmit={onEdit}
      />

      <ConfirmDeleteDialog
        open={openDel}
        onClose={() => setOpenDel(false)}
        title="Xóa tài khoản"
        onConfirm={onDelete}
      />
    </div>
  );
}
