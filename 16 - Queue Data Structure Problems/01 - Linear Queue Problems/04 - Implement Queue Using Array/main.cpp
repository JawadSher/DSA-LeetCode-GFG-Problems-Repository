void MyQueue :: push(int x)
{
    arr[rear++] = x;
}
int MyQueue :: pop()
{
    if(front == rear) return -1;
    return arr[front++];
}
