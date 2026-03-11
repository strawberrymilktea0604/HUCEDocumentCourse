import React, { useLayoutEffect } from "react";
import { Navigate, Route, Routes, useLocation } from "react-router-dom";

import Login from "./pages/Login.jsx";
import Dashboard from "./pages/Dashboard.jsx";
import Profile from "./pages/Profile.jsx";
import Users from "./pages/Users.jsx";
import Materials from "./pages/Materials.jsx";
import Suppliers from "./pages/Suppliers.jsx";
import Inventory from "./pages/Inventory.jsx";
import StockIn from "./pages/StockIn";
import StockOut from "./pages/StockOut";

function RequireAuth({ children }) {
  const authed = localStorage.getItem("authed") === "1";
  if (!authed) return <Navigate to="/login" replace />;
  return children;
}

function HomeRedirect() {
  const authed = localStorage.getItem("authed") === "1";
  return <Navigate to={authed ? "/dashboard" : "/login"} replace />;
}

function useUiScale() {
  useLayoutEffect(() => {
    const BASE_W = 1440;
    const apply = () => {
      const vw = window.innerWidth;
      // “khít” theo chiều ngang
      const scale = vw / BASE_W;

      document.documentElement.style.setProperty("--ui-scale", String(scale));
    };

    apply();
    window.addEventListener("resize", apply);
    return () => window.removeEventListener("resize", apply);
  }, []);
}

export default function App() {
  useUiScale();
  const location = useLocation();

  return (
    <div className="scaleStage">
      <div className="scaleCanvas">
        <div className="scaleRoot">
          <div key={location.pathname} className="pageFade">
            <Routes location={location}>
              <Route path="/" element={<HomeRedirect />} />
              <Route path="/login" element={<Login />} />

              <Route path="/dashboard" element={<RequireAuth><Dashboard /></RequireAuth>} />
              <Route path="/profile" element={<RequireAuth><Profile /></RequireAuth>} />
              <Route path="/users" element={<RequireAuth><Users /></RequireAuth>} />

              <Route path="/materials" element={<RequireAuth><Materials /></RequireAuth>} />
              <Route path="/suppliers" element={<RequireAuth><Suppliers /></RequireAuth>} />
              <Route path="/inventory" element={<RequireAuth><Inventory /></RequireAuth>} />

              <Route path="/stock-in" element={<RequireAuth><StockIn /></RequireAuth>} />
              <Route path="/stock-out" element={<RequireAuth><StockOut /></RequireAuth>} />

              {/* fallback đúng: dùng "*" */}
              <Route path="*" element={<HomeRedirect />} />
            </Routes>
          </div>
        </div>
      </div>
    </div>
  );
}
