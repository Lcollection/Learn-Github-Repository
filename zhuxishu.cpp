namespace tree
{
    #define mid ((l + r) >> 1 )
    #define lson l , mid
    #define rson mid+1 , r
    const int MAGIC = M *30;
    struct p{
        int sum , ls , rs;
    }tr[MAGIC] = {{ 0 , 0 , 0}};
    int sz = 1;
    int N(int sum ,int ls ,int rs)
    {
        if(sz == MAGIC) assert(0);
        tr[sz] = {sum ,ls ,rs};
        return sz++;
    }
    int ins(int o ,int x ,int v ,int l = 1 ,int r = ls)
    {
        if(x < l || x > r) return o;
        const P & t = tr[o];
        if(l == r) return N(t.sum ,x ,v ,lson);
        return N(t.sum + v ,ins(t.ls ,x ,v ,lson) ,ins(t.rs ,x ,v ,rson);
    }
    int query(int o ,int ql ,int qr ,int l = 1 ,int r =ls)
    {
        if(ql > r || l > qr) return 0;
        const P& t = tr[o];
        if(ql <= l && r <= qr) return t.sum;
        return query(t.ls ,ql ,qr ,lson) + query(t,rs ,ql ,qr ,rson);
    }
}