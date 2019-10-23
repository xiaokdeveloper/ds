
/*****************************************************************
 * Copyright (c) 2019
 * All rights reserved.
 * 
 * 文件名称：main.c
 * 文件标识：
 * 文件摘要：
 * 
 * 当前版本：v1.0
 * 作者：xiaok
 * 邮箱：18629086235@163.com
 * 完成日期：2019-10-11
 * 
 * 取代版本：无
 * 作者：无
 * 邮箱：无
 * 完成日期：无
 *****************************************************************/

#include <stdio.h>
#include "myseqlist.h"
/*
 * 函数名称：int main(int argc, char **argv)；  
 * 函数作用：程序的入口；
 * 函数参数说明：
 *              argc：命令行参数个数；
 *              argv：命令行参数；
 * 函数返回值说明：
 *              成功：成功返回0；
 *              失败：失败返回-1；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
int main(int argc, char **argv)
{
    int len = 0;
    int i = 0;

    SeqList mylist;
    InitSeqList(&mylist);
    len = GetSeqListLength(mylist);
    printf("len %d\n", len);
    if (IsEmpty(mylist))
    {
        printf("empty\n");
    }

    /*
    for (i = 0; i < 5; ++i)
    {
        insert_front(&mylist, i);
    }
    
    for (i = 0; i < 4; ++i)
    {
        insert_back(&mylist,i);
    }
    */

    /*
    insert_value(&mylist, 1);
    insert_value(&mylist, 3);
    insert_value(&mylist, 9);
    insert_value(&mylist, 2);
    insert_value(&mylist, 6);
    insert_value(&mylist, 4);
    insert_value(&mylist, 7);
    insert_value(&mylist, 8);
    insert_value(&mylist, 10);
    */

    for (i = 0; i < 9; ++i)
    {
        insert_pos(&mylist, 0, i);
    }
    show_seqlist(mylist);
    delete_front(&mylist);
    show_seqlist(mylist);
    delete_back(&mylist);
    show_seqlist(mylist);
    delete_value(&mylist, 5);
    show_seqlist(mylist);
    delete_value_by_pos(&mylist,1);
    show_seqlist(mylist);
    CleanSeqList(&mylist);
    DestroySeqList(&mylist);
	return 0;
}

