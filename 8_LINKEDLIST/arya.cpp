struct node{

public:
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

node* root = new  node(1);