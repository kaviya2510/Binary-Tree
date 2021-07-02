#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
}*root;
BinaryTree* newnode(int data)
{
    struct BinaryTree* temp=root;
    temp= new BinaryTree;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void preorder(struct BinaryTree* node)
{
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
void inorder(struct BinaryTree *node)
{
    if(node==NULL)
    return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
void postorder(struct BinaryTree *node)
{
    if(node==NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}
void inordernon(struct BinaryTree* root)
{
    struct BinaryTree* current=root;
    stack<BinaryTree*>s;
    while(current!=NULL || s.empty()==false)
    {
        while(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        current=current->right;
    }
}
void preordernon(struct BinaryTree* root)
{
    struct BinaryTree* current=root;
    stack<BinaryTree*>s;
    s.push(current);
    while(!s.empty())
    {
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        if(current->right)
          s.push(current->right);
        if(current->left)
            s.push(current->left);


    }
}
void  postordernon(struct BinaryTree* root)
{
    struct BinaryTree* current=root;
    stack<BinaryTree*>s1,s2;
    s1.push(current);
    while(s1.empty()==false)
    {
        current=s1.top();
        s1.pop();
        s2.push(current);
        if(current->left)
            s1.push(current->left);
        if(current->right)
            s1.push(current->right);
    }
    while(!s2.empty())
    {
        current=s2.top();
        s2.pop();
        cout<<current->data<<" ";

    }
}
void levelordernon(struct BinaryTree* root)
{
    struct BinaryTree* current=root;
    queue<BinaryTree*>q;
    q.push(current);
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
    }
}
int height(struct BinaryTree* current)
{
    if(current==NULL)
        return -1;
    else
    {
        int lheight=height(current->left);
        int rheight=height(current->right);
       if(lheight>rheight)
         return lheight+1;
       else return rheight+1;

    }

}
void printgivenlevel(struct BinaryTree* root,int l)
{
    struct BinaryTree* temp=root;
    if(temp==NULL)
    return;
    if(l==0)
        cout<<temp->data<<" ";
    else if(l>0)
    {
        printgivenlevel(temp->left,l-1);
        printgivenlevel(temp->right,l-1);
    }

}
void levelorder(struct BinaryTree* root)
{
    int h=height(root);
    for(int i=0;i<=h;i++)
        printgivenlevel(root,i);
}
bool searchele(struct BinaryTree* root,int ele)
{
    struct BinaryTree* temp=root;
    if(temp==NULL)
        return false;
    if(temp->data==ele)
        return true;
    int res1=searchele(temp->left,ele);
    if(res1)
        return true;
    int res2=searchele(temp->right,ele);
    if(res2)
        return true;
}
void deletedepest(struct BinaryTree* root,struct BinaryTree* d_node)
{
    struct BinaryTree* temp;
    queue<BinaryTree*>q2;
    q2.push(root);
    while(!q2.empty())
    {
        temp=q2.front();
        q2.pop();
        if(temp==d_node)
        {
            temp=NULL;
            delete(d_node);
            return;
        }
        if(temp->right)
        {
            if(temp->right==d_node)
            {
                temp->right=NULL;
                delete(d_node);
                return;

            }
         else
            q2.push(temp->right);
        }
        if(temp->left)
        {
            if(temp->left==d_node)
            {
                temp->left=NULL;
                delete(d_node);
                return;
            }
            else
                q2.push(temp->left);

        }
    }
}
BinaryTree* deletenode(struct BinaryTree* root,int k)
{
    if(root==NULL)
     return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==k)
            return NULL;
        else
            return root;
    }
    struct BinaryTree* temp;
    struct BinaryTree* keynode=NULL;
    queue<BinaryTree*>q1;
    q1.push(root);
    while(!q1.empty())
    {
        temp=q1.front();
        q1.pop();
        if(temp->data==k)
            keynode=temp;
        if(temp->left)
            q1.push(temp->left);
        if(temp->right)
            q1.push(temp->right);
    }
    if(keynode!=NULL)
    {
        int x=temp->data;
        deletedepest(root,temp);
        keynode->data=x;
    }
    return root;
}
int findsize(struct BinaryTree* root)
{
    struct BinaryTree* temp=root;
    if(temp==NULL)
        return 0;
    else
        return(findsize(temp->left)+1+findsize(temp->right));
}
int findmax(struct BinaryTree* root)
{
    struct BinaryTree* current=root;
    if(root==NULL)
        return INT_MIN;
    int res=current->data;
    int lres=findmax(current->left);
    int rres=findmax(current->right);
    if(lres>res)
        res=lres;
    if(rres>res)
        res=rres;
    return res;
}
int findminimum(struct BinaryTree* root)
{
    struct BinaryTree* current=root;
    if(root==NULL)
        return INT_MAX;
    int res=current->data;
    int lres=findminimum(current->left);
    int rres=findminimum(current->right);
    if(lres<res)
        res=lres;
    if(rres<res)
        res=rres;
    return res;
}
int findsum(struct BinaryTree* root)
{
    struct BinaryTree* temp=root;
    if(temp==NULL)
        return 0;
    return(temp->data + findsum(temp->left) + findsum(temp->right));
}

int main()
{
    int ch;
    root=newnode(1);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right=newnode(3);
    while(1){
    cout<<endl;
    cout<<"  1.Inorder(Recursive)"<<endl;
    cout<<"  2.Preorder(Recursive)"<<endl;
    cout<<"  3.Postorder(recursive)"<<endl;
    cout<<"  4.Inorder(non recursive):"<<endl;
    cout<<"  5.Preorder(non recursive):"<<endl;
    cout<<"  6.Postorder(non recursive):"<<endl;
    cout<<"  7.Height of tree"<<endl;
    cout<<"  8.level order traversal(non-recursive):"<<endl;
    cout<<"  9.level order traversal(recursive):"<<endl;
    cout<<"  10.Search for an element"<<endl;
    cout<<"  11.Delete a node"<<endl;
    cout<<"  12.size of the tree"<<endl;
    cout<<"  13.Maximum ele in tree"<<endl;
    cout<<"  14.Minimum element in a tree"<<endl;
    cout<<"  15.Sum of all nodes"<<endl;
    cout<<"Enter the choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Inorder:";
        inorder(root);
        break;
    case 2:
        cout<<"Preorder:";
        preorder(root);
        break;
    case 3:
        cout<<"Postorder:";
        postorder(root);
        break;
    case 4:
        cout<<"Inorder(non-recur):";
        inordernon(root);
        break;
    case 5:
        cout<<"Preorder(non-recur):";
        preordernon(root);
        break;
    case 6:
        cout<<"Postorder(non-recur):";
        postordernon(root);
        break;
    case 7:
        cout<<"Height of the tree is:";
        cout<<height(root);
        break;
    case 8:
        cout<<"Levelorder(non-recur):";
        levelordernon(root);
        break;
    case 9:
        cout<<"Level order(recur):";
        levelorder(root);
        break;
    case 10:
        int ele;
        cout<<"Enter the element u want to search:";
        cin>>ele;
        if(searchele(root,ele))
            cout<<"The element"<<ele<<" is present in the tree"<<endl;
        else
            cout<<"The element"<<ele<<" is not present in the tree"<<endl;
    case 11:
        int ele1;
        cout<<"Enter the element you want to delete:";
        cin>>ele1;
        root=deletenode(root,ele1);
    case 12:
        cout<<"The size of the tree is:";
        cout<<findsize(root);
    case 13:
        cout<<"The maximum element in a  binary tree is:"<<findmax(root);
        break;
    case 14:
        cout<<"The minimum elemt in a binary tree is:"<<findminimum(root);
        break;
    case 15:
        cout<<"The sum of all nodes in a binary tree is:"<<findsum(root);

    }
    }

}
