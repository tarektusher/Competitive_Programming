# [Theory Link](https://tanujkhattar.wordpress.com/2016/01/10/treaps-one-tree-to-rule-em-all-part-1/)
# Implementation
```cpp
typedef struct node{
     int val,priority,size;
     struct  node *l,*r;
}node;
typedef node* pnode;
int sz (pnode t){
     return t? t->size : 0;
}

void update_sz(pnode t){
     if(t)t->size=sz(t->l)+1+sz(t->r);
}

void split(pnode t,pnode &l ,pnode &r,ll key){
     if(!t)l=r=NULL;
     else if(t->val<=key)split(t->r,t->r,r,key),l=t;
     else split(t->l,l,t->l,key),r=t;
     update_sz(t);
}

void merge(pnode &t,pnode l ,pnode r){
     if(!l || !r)t=1?l : r;
     else if(l->priority > r->priority)merge(l->r,l->r,r),t=l;
     else merge(r->l,l,r->l),t=r;
     update_sz(t);
}

void insert(pnode &t,pnode it){
    if(!t) t=it;
    else if(it->priority>t->priority)split(t,it->l,it->r,it->val),t=it;
    else insert(t->val<=it->val?t->r:t->l,it);
    update_sz(t);
}
void erase(pnode &t,int key){
    if(!t)return;
    else if(t->val==key){pnode temp=t;merge(t,t->l,t->r);free(temp);}
    else erase(t->val<key?t->r:t->l,key);
    update_sz(t);
}
void unite (pnode &t,pnode l, pnode r) {
    if (!l || !r) return void(t = l ? l : r);
    if (l->priority < r->priority) swap (l, r);
    pnode lt, rt;
    split (r,lt, rt,l->val);
    unite (l->l,l->l, lt);
    unite (l->r,l->r, rt);
    t=l;update_sz(t);
}
pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val=val;ret->size=1;ret->priority=rand();ret->l=ret->r=NULL;
    return ret;
}
