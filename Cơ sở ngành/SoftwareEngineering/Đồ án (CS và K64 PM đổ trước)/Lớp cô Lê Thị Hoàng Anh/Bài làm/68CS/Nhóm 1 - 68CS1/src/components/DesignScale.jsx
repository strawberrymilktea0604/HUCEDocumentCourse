import React from "react";

export default function DesignScale({
  children,
  designWidth = 1440,
  maxScale = 1,
  minScale = 0.6,
}) {
  const [scale, setScale] = React.useState(1);

  React.useEffect(() => {
    const calc = () => {
      const s = window.innerWidth / designWidth;
      const clamped = Math.max(minScale, Math.min(maxScale, s));
      setScale(clamped);
    };
    calc();
    window.addEventListener("resize", calc);
    return () => window.removeEventListener("resize", calc);
  }, [designWidth, maxScale, minScale]);

  return (
    <div
      style={{
        width: "100vw",
        height: "100vh",
        overflow: "auto",
        background: "#EBF4F9",
      }}
    >
      {/* sizer để scroll đúng kích thước sau khi scale */}
      <div
        style={{
          width: designWidth * scale,
          margin: "0 auto",
        }}
      >
        <div
          style={{
            width: designWidth,
            transform: `scale(${scale})`,
            transformOrigin: "top left",
          }}
        >
          {children}
        </div>
      </div>
    </div>
  );
}
