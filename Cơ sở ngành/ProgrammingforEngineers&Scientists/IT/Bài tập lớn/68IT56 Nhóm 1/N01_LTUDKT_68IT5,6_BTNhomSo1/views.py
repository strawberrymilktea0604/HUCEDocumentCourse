from flask import Blueprint, render_template, request, jsonify, redirect, url_for,flash
import json, os,re
from rooms import Room, StandardRoom, DeluxeRoom

views = Blueprint(__name__, "views")

# Route home + hien thi danh sach
@views.route("/")
def home():
    file_path = os.path.join(os.path.dirname(__file__), "rooms.json")
    with open(file_path, "r", encoding="utf-8") as f:
        raw_rooms = json.load(f)

    search = request.args.get("search", "").lower()
    room_type = request.args.get("type", "")
    status = request.args.get("status", "")

    rooms = []
    for r in raw_rooms:
        if search and search not in r["rid"].lower():
            continue
        if room_type and r["type"] != room_type:
            continue
        if status and r["status"] != status:
            continue
        if r["type"] == "Phòng thường":
            room = StandardRoom(
                rid=r["rid"],
                price=r["price"],
                status=r["status"],
                area=r["area"],
                bed_count=r["bed_count"]
            )
        elif r["type"] == "Phòng cao cấp":
            room = DeluxeRoom(
                rid=r["rid"],
                price=r["price"],
                status=r["status"],
                area=r["area"],
                bed_count=r["bed_count"],
                services=r.get("services", [])
            )
        else:
            room = Room(r["rid"], r["type"], r["price"], r["status"])

        rooms.append(room)
    
    total_revenue = 0
    standard_revenue = 0
    deluxe_revenue = 0

    for r in raw_rooms:
        if r["status"] == "Đã đặt":
            total_revenue += r["price"]
            if r["type"] == "Phòng thường":
                standard_revenue += r["price"]
            elif r["type"] == "Phòng cao cấp":
                deluxe_revenue += r["price"]


    return render_template("index.html", 
                           rooms=rooms,
                           total_revenue=total_revenue,
                            standard_revenue=standard_revenue,
                            deluxe_revenue=deluxe_revenue)

#Route sua phong
@views.route("/edit-room/<rid>", methods=["GET", "POST"])
def edit_room(rid):
    file_path = os.path.join(os.path.dirname(__file__), "rooms.json")

    with open(file_path, "r+", encoding="utf-8") as f:
        rooms = json.load(f)
        room = next((r for r in rooms if r["rid"] == rid), None)

        if not room:
            flash("Không tìm thấy phòng!", "error")
            return redirect(url_for("views.home"))

        if request.method == "POST":
            try:
                price = float(request.form["price"])
                area = int(request.form["area"])
                bed_count = int(request.form["bed_count"])
            except ValueError:
                flash("Giá, diện tích và số giường phải là số hợp lệ!", "error")
                return render_template("edit_room.html", room=room)

            if price <= 0 or area <= 0 or bed_count <= 0:
                flash("Giá, diện tích và số giường phải > 0!", "error")
                return render_template("edit_room.html", room=room)

            room["type"] = request.form["type"]
            room["price"] = price
            room["status"] = request.form["status"]
            room["area"] = area
            room["bed_count"] = bed_count
            room["services"] = request.form.getlist("services")

            f.seek(0)
            f.truncate()
            json.dump(rooms, f, ensure_ascii=False, indent=4)

            return redirect(url_for("views.home"))

        return render_template("edit_room.html", room=room)


#Route Xoa Phong
@views.route("/delete-room/<rid>", methods=["POST"])
def delete_room(rid):
    file_path = os.path.join(os.path.dirname(__file__), "rooms.json")

    with open(file_path, "r+", encoding="utf-8") as f:
        rooms = json.load(f)
        updated_rooms = [room for room in rooms if room["rid"] != rid]
        f.seek(0)
        f.truncate()  
        json.dump(updated_rooms, f, ensure_ascii=False, indent=4)

    return redirect(url_for("views.home"))

# Route Them Phong
@views.route("/add-room", methods=["GET", "POST"])
def add_room():
    if request.method == "POST":
        rid = request.form["rid"]
        if not re.match("^[A-Za-z0-9_-]+$", rid):
            flash("Mã phòng không được chứa ký tự đặc biệt!", "error")
            return render_template("add_room.html")
        type = request.form["type"]
    
        try:
            price = float(request.form["price"])
            area = int(request.form["area"])
            bed_count = int(request.form["bed_count"])
        except ValueError:
            flash("Giá, diện tích và số giường phải là số hợp lệ!", "error")
            return render_template("add_room.html")

        if price <= 0 or area <= 0 or bed_count <= 0:
            flash("Giá, diện tích và số giường phải > 0!", "error")
            return render_template("add_room.html")

        status = request.form["status"]
        services = request.form.getlist("services")

        file_path = os.path.join(os.path.dirname(__file__), "rooms.json")

        with open(file_path, "r+", encoding="utf-8") as f:
            rooms = json.load(f)

            for room in rooms:
                if room["rid"] == rid:
                    flash("Phòng với mã số này đã tồn tại!", "error")
                    return render_template("add_room.html")

            new_room = {
                "rid": rid,
                "type": type,
                "price": price,
                "status": status,
                "area": area,
                "bed_count": bed_count,
                "services": services
            }

            rooms.append(new_room)
            f.seek(0)
            f.truncate()
            json.dump(rooms, f, ensure_ascii=False, indent=4)

        return redirect(url_for("views.home"))

    return render_template("add_room.html")


