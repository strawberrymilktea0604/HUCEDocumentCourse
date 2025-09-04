public class DiemAm extends IllegalArgumentException {
    public DiemAm() {
        super("Diem bai kiem tra khong hop le");
    }
    public DiemAm(int diemso)
    {
        super("Diem bai kiem tra " + diemso + "khong hop le");
    }
}
