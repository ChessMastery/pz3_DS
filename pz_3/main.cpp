#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

using namespace std;

struct btree
{
   int elem;
   btree *left, *right;
   btree(int _elem = 0, btree *_left = NULL, btree *_right = NULL) : elem(_elem), left(_left), right(_right) {}
} *root = new btree;

void PutNum(int num, btree *d) // подпрограмма случайного включения элементов
{
   if (rand() % 2)
      if (!d->right)
         d->right = new btree(num);
      else
         PutNum(num, d->right);
   else
      if (!d->left)
         d->left = new btree(num);
      else
         PutNum(num, d->left);
}

void BuildTree() // подпрограмма считывания элементов
{
   int num, i = 0;
   btree *d = root;
   srand(time(NULL));
   printf_s("Введите количество элементов в дереве: ");
   scanf_s("%d", &i);
   printf_s("Введите элементы дерева (тип int): \n");
   for (int k = 0; k < i; d = root, ++k)
   {
      scanf_s("%d", &num);
      if (!k)
         d->elem = num;
      else
         PutNum(num, d);
   }
}

void PrintTree(btree *node) // подпрограмма вывода бинарного дерева по уровням
{
   queue<btree *> Q;
   Q.push(node);
   Q.push(NULL);
   do
   {
      node = Q.front();
      Q.pop();
      if (node)
      {
         printf_s("%d ", node->elem);
         if (node->left)
            Q.push(node->left);
         if (node->right)
            Q.push(node->right);
      }
      else
      {
         printf_s("\n");
         if (!Q.empty())
            Q.push(NULL); // уровень пройден, все вершины следующего уровня в очереди - добавляем перенос в конец очереди
      }
   } while
      (!Q.empty());
}

int main()
{
   setlocale(LC_ALL, "Russian");
   BuildTree();
   PrintTree(root);
   return 0;
}
