#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct dictNode{
  int key;
  char* value;
}dictNode;

dictNode* dict[20];

dictNode* createDictNode(int key, char value[]){
  dictNode* d = (dictNode*)malloc(sizeof(dictNode));
  d->key = key;
  d->value = value;
  return d;
}

typedef struct node
{
	int key;
  char* value;
	struct node *left, *right;
}node;

node* latest = NULL;
node* temp = NULL;

node* create(int n, char value[])
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->key = n;
  newnode->value = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}

node* insert(node* node, int key, char value[])
{
	if(node==NULL) return create(key, value);
	if(key< node->key)
	{
		node->left = insert(node->left, key, value);
		latest = node->left;
		
	}
	

	else if(key > node->key)
	{
		node->right = insert(node->right, key, value);
		latest = node->right;
	}
	
	return node;

}

void preorder(struct node* root) 
{ 
    if (root != NULL) 
    { 
        if(root->value != NULL ){
          printf("%s\n", root->value);
        }
        preorder(root->left); 
        preorder(root->right);
    } 
} 

void tree()
{
	node* root = NULL;
	root = insert(root, 100, "\nIs it an animal?");
    temp = root;
	int count, p, start, nl, nr;
	count = 5, p = 2, start = 100;

	

	
    insert(root, 85, "\nIs it a bird?");
insert(root, 116, "\nIs it a plant?");
insert(root, 60, "\nIs it a flightless bird?");
insert(root, 96, "\nIs it a fish?");
insert(root, 110, "\nIs it a flowering plant?");
insert(root, 122, "\nIs it an electronic equipment?");
insert(root, 50, "\nIs it native to Australia?");
insert(root, 70, "\nIs it a carnivore?");
insert(root, 90, "\nIs it a carnivore?");
insert(root, 98, "\nIs it domesticated?");
insert(root, 105, "\nDoes it grow in water?");
insert(root, 112, "\nDoes it bear fruits?");
insert(root, 120, "\nDo you find it in the kitchen?");
insert(root, 140, "\nIs it a piece of furniture?");
///////
insert(root, 40, "EMU");
insert(root, 55, "KIWI");
insert(root, 65, "EAGLE");
insert(root, 75, "PARROT");
insert(root, 87, "SHARK");
insert(root, 94, "SURGEONFISH");
insert(root, 99, "TIGER");
insert(root, 97, "DOG");
insert(root, 104, "LOTUS");
insert(root, 107, "LILY");
insert(root, 111, "MANGO TREE");
insert(root, 113, "MONEY PLANT");
insert(root, 118, "REFRIGERATOR");
insert(root, 121, "COMPUTER");
insert(root, 135, "TABLE");
insert(root, 145, "BOOK");

  //printf("Choose from the options below:\n");
	//preorder(root);
	temp = root;
		
}


void move(int r){

int m;
    printf(temp->value);
    if(temp->left!=NULL || temp->right!=NULL)
    {
        
        scanf("%d" ,&m);
        if(m==1)
        {
            
            temp = temp->left;
            move(m);
        }

        else{
            
            temp = temp->right;
            move(m);
        }
    }
    else
    {
        printf("\nGAME OVER\n ");
    }
  
}





int main()
{

  

  
	printf("~GAME\n");
	printf("Welcome to the game!\nWe will now ask you a few questions to guess what you are talking about!\n");
	tree();
	int r;
    printf("Enter 1 to start game: ");
    scanf("%d" ,&r);
	/*printf("\nIs it an animal? \nIf yes, enter 1 otherwise enter 0");
	
	scanf("%d" ,&r);
    printf("Input accepted\n");*/
	move(r);
	
	

}
