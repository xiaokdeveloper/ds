
/*****************************************************************
 * Copyright (c) 2019
 * All rights reserved.
 * 
 * 文件名称：myseqlist.h
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

#ifndef _MYSEQLIST_H_
#define _MYSEQLIST_H_
#include "utili.h"

/*
 * 结构体名：SeqList
 * 作用：顺序表结构体类型
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
typedef struct SeqList
{
    ElemType *base; // 指向数据空间
    int capacity;   // 数据空间容量
    int size;       // 实际使用空间大小
}SeqList;

// 初始化顺序表,成功返回True，失败返回False
Bool InitSeqList(SeqList *seq);
// 销毁顺序表,成功返回True，失败返回False
Bool DestroySeqList(SeqList *seq);
// 清空顺序表，成功返回True，失败返回False
Bool CleanSeqList(SeqList *seq);
// 判断顺序表表是否为空,空返回True，不空返回False
Bool IsEmpty(SeqList seq);
// 获取顺序表的长度
int GetSeqListLength(SeqList seq);
// 获取第i个元素
Bool GetElem(SeqList *seq, int index, ElemType *elem);
// 头插，从顺序表头部插入
Bool insert_front(SeqList *seq, ElemType val);
// 尾插
Bool insert_back(SeqList *seq, ElemType val);
// 按值插入，按照从小到大的顺序
Bool insert_value(SeqList *seq, ElemType val);
// 按照位置插入
Bool insert_pos(SeqList *seq, int pos, ElemType val);
// 头删
Bool delete_front(SeqList *seq);
// 尾删
Bool delete_back(SeqList *seq);
// 按值删除，要求不能有重复的，当有重复时，只删除第一个元素
Bool delete_value(SeqList *seq, ElemType val);
// 按值删除，删除顺序表中出现的所有元素
Bool delete_value_all(SeqList *seq, ElemType val);
// 按照位置删除、
Bool delete_value_by_pos(SeqList *seq, int pos);
// 打印整个顺序表
Bool show_seqlist(SeqList seq);
// 排序,这里先只实现冒泡排序，更多更复杂排序，专题整理
Bool sort_seqlist(SeqList *seq);
//  逆置
Bool Resver(SeqList *seq);
// 查找数据
Bool find(SeqList *seq, ElemType item);
#endif
