def them_gia_tri(x, ds=None):
    if ds is None:
        ds = []
    ds.append(x)
    return ds

ds = None
ds = them_gia_tri(1, ds)
ds = them_gia_tri(2, ds)
print(ds)