import React from "react";

export function NutMilkLogo({ size = 42 }) {
  return (
    <svg width={size} height={size} viewBox="0 0 64 64" aria-hidden="true">
      <defs>
        <linearGradient id="g" x1="0" x2="1">
          <stop offset="0" stopColor="#2f9f67" />
          <stop offset="1" stopColor="#7ccf4f" />
        </linearGradient>
      </defs>
      <path d="M32 6c10 9 18 19 18 30 0 11-8 20-18 20S14 47 14 36C14 25 22 15 32 6z" fill="url(#g)" />
      <path d="M31 18c-2 6-2 11-2 18 0 9 4 15 10 19-10-2-17-10-17-20 0-6 3-12 9-17z" fill="#1f6aa8" opacity=".55"/>
    </svg>
  );
}

export function Icon({ name, size = 22 }) {
  const common = { width: size, height: size, viewBox: "0 0 24 24", fill: "none", stroke: "currentColor", strokeWidth: "2", strokeLinecap: "round", strokeLinejoin: "round" };
  switch (name) {
    case "search":
      return <svg {...common}><circle cx="11" cy="11" r="7"/><path d="M21 21l-4.3-4.3"/></svg>;
    case "bell":
      return <svg {...common}><path d="M18 8a6 6 0 10-12 0c0 7-3 7-3 7h18s-3 0-3-7"/><path d="M13.73 21a2 2 0 01-3.46 0"/></svg>;
    case "user":
      return <svg {...common}><path d="M20 21a8 8 0 10-16 0"/><circle cx="12" cy="7" r="4"/></svg>;
    case "menu":
      return <svg {...common}><path d="M4 6h16"/><path d="M4 12h16"/><path d="M4 18h16"/></svg>;
    case "home":
      return <svg {...common}><path d="M3 11l9-8 9 8"/><path d="M9 22V12h6v10"/></svg>;
    case "profile":
      return <svg {...common}><circle cx="12" cy="8" r="4"/><path d="M4 22a8 8 0 0116 0"/></svg>;
    case "users":
      return <svg {...common}><path d="M17 21v-2a4 4 0 00-4-4H5a4 4 0 00-4 4v2"/><circle cx="9" cy="7" r="4"/><path d="M23 21v-2a4 4 0 00-3-3.87"/><path d="M16 3.13a4 4 0 010 7.75"/></svg>;
    case "boxout":
      return <svg {...common}><path d="M21 16V8a2 2 0 00-1-1.73L13 2.27a2 2 0 00-2 0L4 6.27A2 2 0 003 8v8a2 2 0 001 1.73l7 4a2 2 0 002 0l7-4a2 2 0 001-1.73z"/><path d="M12 22V12"/><path d="M16 12l4-2"/><path d="M8 12L4 10"/></svg>;
    case "boxin":
      return <svg {...common}><path d="M21 16V8a2 2 0 00-1-1.73L13 2.27a2 2 0 00-2 0L4 6.27A2 2 0 003 8v8a2 2 0 001 1.73l7 4a2 2 0 002 0l7-4a2 2 0 001-1.73z"/><path d="M12 22V12"/><path d="M12 7v6"/><path d="M9 10h6"/></svg>;
    case "materials":
      return <svg {...common}><path d="M4 4h16v16H4z"/><path d="M8 4v16"/></svg>;
    case "supplier":
      return <svg {...common}><path d="M3 21h18"/><path d="M6 21V7l6-4 6 4v14"/><path d="M9 21v-6h6v6"/></svg>;
    case "checklist":
      return <svg {...common}><path d="M9 11l3 3L22 4"/><path d="M21 12v7a2 2 0 01-2 2H5a2 2 0 01-2-2V5a2 2 0 012-2h11"/></svg>;
    case "x":
      return <svg {...common}><path d="M18 6L6 18"/><path d="M6 6l12 12"/></svg>;
    case "eye":
      return <svg {...common}><path d="M2 12s4-7 10-7 10 7 10 7-4 7-10 7S2 12 2 12z"/><circle cx="12" cy="12" r="3"/></svg>;
    case "arrowDown":
      return <svg {...common}><path d="M12 3v14"/><path d="M7 12l5 5 5-5"/></svg>;
    case "arrowUp":
      return <svg {...common}><path d="M12 21V7"/><path d="M7 12l5-5 5 5"/></svg>;
    default:
      return <svg {...common}><circle cx="12" cy="12" r="9"/></svg>;
  }
}
