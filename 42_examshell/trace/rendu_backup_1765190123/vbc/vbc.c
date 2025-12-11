#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //igual

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    } type;
    int val;
    struct node *l;
    struct node *r; //igual
} node;

node *parse_expression(char **s);
node *parse_addition(char **s);
node *parse_multiplication(char **s);
node *parse_primary(char **s);
node *new_node(node n);
void destroy_tree(node *n);
int eval_tree(node *tree);
void unexpected(char c);
int accept(char **s, char c);
int expect(char **s, char c);

node *new_node(node n)  //igual
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return NULL;
    *ret = n;
    return ret;
}

void destroy_tree(node *n)  //no cambia
{
    if (!n)
        return;

    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void unexpected(char c)  //end of file cambia por end of imput
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c)   //esta coomparacion cambia if (**s == c)
{
    if (**s == c)
    {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char **s, char c) //no cambia
{
    if (accept(s, c))
        return 1;
    unexpected(**s);
    return 0;
}

node *parse_primary(char **s)
{
    node *res;
    node tmp;

    if (**s == '(')
    {
        (*s)++;
        res = parse_addition(s);

        if (!res || **s != ')')
        {
            destroy_tree(res);
            unexpected(**s);
            return NULL;
        }

        (*s)++;
        return res;
    }

    if (isdigit(**s))
    {
        tmp.type = VAL;
        tmp.val = **s - '0';
        tmp.l = NULL;
        tmp.r = NULL;

        res = new_node(tmp);
        (*s)++;
        return res;
    }

    unexpected(**s);
    return NULL;
}

node *parse_multiplication(char **s)
{
    node *left;
    node *right;
    node tmp;

    left = parse_primary(s);
    if (!left)
        return NULL;

    while (**s == '*')
    {
        (*s)++;

        right = parse_primary(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }

        tmp.type = MULTI;
        tmp.l = left;
        tmp.r = right;
        tmp.val = 0;

        left = new_node(tmp);
        if (!left)
        {
            destroy_tree(right);
            return NULL;
        }
    }

    return left;
}

node *parse_addition(char **s)
{
    node *left;
    node *right;
    node tmp;

    left = parse_multiplication(s);
    if (!left)
        return NULL;

    while (**s == '+')
    {
        (*s)++;

        right = parse_multiplication(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }

        tmp.type = ADD;
        tmp.l = left;
        tmp.r = right;
        tmp.val = 0;

        left = new_node(tmp);
        if (!left)
        {
            destroy_tree(right);
            return NULL;
        }
    }

    return left;
}

node *parse_expression(char **s)
{
    node *ret = parse_addition(s);

    if (!ret)
        return NULL;

    if (**s)
    {
        destroy_tree(ret);
        unexpected(**s);
        return NULL;
    }

    return ret;
}

int eval_tree(node *tree) //no cambia
{
    switch (tree->type)
    {
        case ADD:
            return eval_tree(tree->l) + eval_tree(tree->r);
        case MULTI:
            return eval_tree(tree->l) * eval_tree(tree->r);
        case VAL:
            return tree->val;
    }

    return 0;
}

int main(int argc, char **argv) //no cambia
{
    if (argc != 2)
        return 1;

    char *input = argv[1];
    node *tree = parse_expression(&input);

    if (!tree)
        return 1;

    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
}
