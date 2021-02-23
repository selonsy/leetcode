package main

import (
	"container/list"
	"errors"
	"fmt"
)

type Stack struct {
	MaxTop int // 栈最大可以存放的个数
	Top    int // 栈顶
	arr    [5]int
}

func (s *Stack) Push(val int) (err error) {
	if s.isFull() {
		return errors.New("full")
	}
	s.Top++
	//放入数据
	s.arr[s.Top] = val
	return
}

func (s *Stack) Pop() (val int, err error) {
	if s.isEmpty() {
		return 0, errors.New("empty")
	}
	val = s.arr[s.Top]
	s.Top--
	return val, nil
}

func (s *Stack) List() {
	if s.isEmpty() {
		fmt.Println("empty")
		return
	}
	for i := s.Top; i >= 0; i-- {
		fmt.Println(s.arr[i])
	}
}

func (s *Stack) isEmpty() bool {
	return s.Top == -1
}

func (s *Stack) isFull() bool {
	return s.Top == s.MaxTop-1
}

func stackWithContainerList() {
	// 双向链表
	stack := list.New()

	stack.PushBack(1)
	stack.PushBack(2)
	stack.PushBack(3)

	// 顺序遍历(类似于队列，先进先出)
	fmt.Println("FIFO:")
	for e := stack.Front(); e != nil; e = e.Next() {
		fmt.Println(e.Value)
	}
	// 逆序遍历(类似于栈，先进后出)
	fmt.Println("FILO:")
	for e := stack.Back(); e != nil; e = e.Prev() {
		fmt.Println(e.Value)
	}
	// 出栈
	num := stack.Back()
	fmt.Println("pop:", num.Value)
	stack.Remove(num)
}

func queueAndStackWithSlice() {
	// 初始化
	var queue []int
	var stack []int

	// 入队 入栈
	queue = append(queue, 1)
	queue = append(queue, 2)
	queue = append(queue, 3)

	stack = append(stack, 1)
	stack = append(stack, 2)
	stack = append(stack, 3)

	// 出队 出栈
	queue = queue[1:]
	stack = stack[0 : len(stack)-1]

	fmt.Println(queue)
	fmt.Println(stack)
}

func main() {
	stack := &Stack{
		MaxTop: 5,
		Top:    -1,
	}

	stack.Push(1)
	stack.Push(2)
	stack.Push(3)

	stack.List()
	val, _ := stack.Pop()
	fmt.Println("Pop:", val)
	stack.List()

	stackWithContainerList()
}
