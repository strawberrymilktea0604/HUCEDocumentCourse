public class LonHon100 extends IllegalArgumentException {
    public LonHon100() {
        super("Diem bai kiem tra khong hop le");
    }
    public LonHon100(int diemso)
    {
        super("Diem bai kiem tra " + diemso + "khong hop le");
    }
}
