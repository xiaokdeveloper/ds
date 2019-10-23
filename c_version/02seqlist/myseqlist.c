
/*****************************************************************
 * Copyright (c) 2019
 * All rights reserved.
 * 
 * 文件名称：myseqlist.c
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

#include "utili.h"
#include "myseqlist.h"

/*
 * 函数名称：Bool InitSeqList(SeqList *seq);
 * 函数作用：初始化顺序表；
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool InitSeqList(SeqList *seq)
{
    seq->capacity = SEQLIST_INIT_SIZE;
    seq->base = (ElemType*)malloc(sizeof(ElemType) * seq->capacity);
    if (NULL == seq->base)
    {
        return False;
    }
    seq->size = 0;
    return True;
}

/*
 * 函数名称：Bool DestroySeqList(SeqList *seq);
 * 函数作用：销毁顺序表;
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool DestroySeqList(SeqList *seq)
{
    if (NULL == seq)
    {
        return False;
    }
    seq->capacity = 0;
    seq->size = 0;
    free(seq->base);
    seq->base = NULL;
    return True;
}

/*
 * 函数名称：Bool CleanSeqList(SeqList *seq);
 * 函数作用：清空顺序表，与摧毁的区别是，不释放空间;
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool CleanSeqList(SeqList *seq)
{
    if (NULL == seq)
    {
        return False;
    }

    seq->size = 0;
    return True;
}

/*
 * 函数名称：Bool IsEmpty(SeqList seq);
 * 函数作用：判断顺序表是否为空;
 * 函数参数说明：
 *              seq：顺序表，该函数不需要修改顺序表的内容，因而以值传递；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool IsEmpty(SeqList seq)
{
    if (seq.size == 0)
        return True;
    return False;
}

/*
 * 函数名称：int GetSeqListLength(SeqList seq)；
 * 函数作用：获取顺序表的数据长度；
 * 函数参数说明：
 *              seq：顺序表，该函数不需要修改顺序表的内容，因而以值传递；
 * 函数返回值说明：
 *              返回实际大小；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
int GetSeqListLength(SeqList seq)
{
    return seq.size;
}

/*
 * 函数名称：Bool GetElem(SeqList *seq, int index, int *elem)；
 * 函数作用：获取顺序表指定位置元素，通过elem带回该值；
 * 函数参数说明：
 *              *seq：顺序表；
 *              index：下标；
 *              elem:成功带回指定位置元素的值；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool GetElem(SeqList *seq, int index, int *elem)
{
    // 判断index 是否非法
    if (index < 0 || index > seq->size )
    {
        return False;
    }
    *elem = seq->base[index];
    return True;
}

/*
 * 函数名称：Bool insert_front(SeqList *seq, ElemType val)； 
 * 函数作用：头插；
 * 函数参数说明：
 *              *seq：顺序表；
 *              val：需要插入的数据；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool insert_front(SeqList *seq, ElemType val)
{
    int i = 0;
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (seq->size == seq->capacity)
    {
        printf("out of memory\n");
        return False;
    }

    for (i = seq->size; i > 0; --i)
    {
        seq->base[i] = seq->base[i - 1];
    }
    seq->base[0] = val;
    seq->size++;
    return True;
}

/*
 * 函数名称：Bool insert_back(SeqList *seq, ElemType val)；
 * 函数作用：尾插；
 * 函数参数说明：
 *              *seq：顺序表；
 *              val：需要插入的数据；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool insert_back(SeqList *seq, ElemType val)
{
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (seq->size == seq->capacity)
    {
        printf("out of memory\n");
        return False;
    }

    seq->base[seq->size++] = val;
    return True;
}

/*
 * 函数名称：Bool show_seqlist(SeqList seq)；
 * 函数作用：打印顺序表；
 * 函数参数说明：
 *              seq：顺序表，不需要修改，以值传递；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool show_seqlist(SeqList seq)
{
    int i = 0;
    if (NULL == seq.base)
    {
        return False;
    }

    for (i = 0; i < seq.size; ++i)
    {

        printf("%d ",seq.base[i]);
    }
    printf("nal\n");
    return True;
}

/*
 * 函数名称：Bool insert_value(SeqList *seq, ElemType val)；
 * 函数作用：按值插入，采用升序，并且顺序表内元素不会重复；
 * 函数参数说明：
 *              *seq：顺序表；
 *              val：需要插入的元素；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool insert_value(SeqList *seq, ElemType val)
{
    int i = 0;
    int j = 0;

    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (seq->size == seq->capacity)
    {
        printf("out of memory\n");
        return False;
    }

    for (i = 0; i < seq->size; ++i)
    {
        if (val < seq->base[i])
        {
            break;
        }
    }

    /*
    if (i == seq->size)
    {
        seq->base[seq->size++] = val;
        return True;
    }
    */
    j = seq->size;
    for (j = seq->size; j > i; --j)
    {
        seq->base[j] = seq->base[j - 1];
    }

    seq->base[j] = val;
    seq->size++;

    return True;
}

/*
 * 函数名称：Bool insert_pos(SeqList *seq, int pos, ElemType val)；
 * 函数作用：按照位置插入；
 * 函数参数说明：
 *              *seq：顺序表；
 *              pos：即将插入的位置；
 *              val：需要插入的元素；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool insert_pos(SeqList *seq, int pos, ElemType val)
{
    int i = 0;
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    /*
    // 空间是否已经满了
    if (seq->size == seq->capacity)
    {
        printf("out of memory\n");
        return False;
    }
    */

    // 坐标是否合法
    if (pos < 0 || pos > seq->size)
    {
        printf("out of index\n");
        return False;
    }

    for (i = seq->size; i > pos; --i)
    {
        seq->base[i] = seq->base[i - 1];
    }

    seq->base[pos] = val;
    seq->size++;
    return True;
}

/*
 * 函数名称：Bool delete_front(SeqList *seq)；
 * 函数作用：头删；
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool delete_front(SeqList *seq)
{
    int i = 0;
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (IsEmpty(*seq))
    {
        printf("empty\n");
        return False;
    }

    for (i = 0; i < seq->size - 1; ++i)
    {
        seq->base[i] = seq->base[i + 1];
    }

    seq->size--;
    return True;
}

/*
 * 函数名称：Bool delete_back(SeqList *seq)；
 * 函数作用：尾删；
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool delete_back(SeqList *seq)
{
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (IsEmpty(*seq))
    {
        printf("empty\n");
        return False;
    }

    seq->size--;
    return False;
}

/*
 * 函数名称：Bool delete_value(SeqList *seq, ElemType val)；
 * 函数作用：按值删除，该方法只会删除从头到尾遇到的第一个元素；
 * 函数参数说明：
 *              *seq：顺序表；
 *              val：需要删除的元素值；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool delete_value(SeqList *seq, ElemType val)
{
    int i = 0;
    int j = 0;
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (IsEmpty(*seq))
    {
        printf("empty\n");
        return False;
    }

    for (i = 0; i < seq->size; ++i)
    {
        if (seq->base[i] == val)
        {
            for (j = i; j < seq->size; ++j)
            {
                seq->base[j] = seq->base[j + 1];
            }

            printf("%d have delete\n", val);
            seq->size--;
            break;
        }
    }

    return True;
}

/*
 * 函数名称：Bool delete_value_by_pos(SeqList *seq, int pos)；
 * 函数作用：按照位置删除；
 * 函数参数说明：
 *              *seq：顺序表；
 *              pos：下标；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool delete_value_by_pos(SeqList *seq, int pos)
{
    int i = 0;
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (IsEmpty(*seq))
    {
        printf("empty\n");
        return False;
    }

    if (pos < 0 || pos >= seq->size)
    {
        printf("out of range\n");
        return False;
    }

    for (i = pos; i < seq->size; ++i)
    {
        seq->base[i] = seq->base[i + 1];
    }

    seq->size--;
    return False;
}

/*
 * 函数名称：Bool sort_seqlist(SeqList *seq)；
 * 函数作用：排序，采用冒泡排序；
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool sort_seqlist(SeqList *seq)
{
    int i = 0;
    int j = 0;
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (IsEmpty(*seq))
    {
        printf("empty\n");
        return False;
    }

    for (i = 0; i < seq->size - 1; ++i)
    {
        for (j = 0; j < seq->size - i - 1; ++j)
        {
            if (seq->base[j] > seq->bas[j + 1])
            {
                ElemType tmp = seq->base[j];
                seq->base[j] = seq->base[j + 1];
                seq->base[j + 1] = tmp;
            }
        }
    }
    return True;
}

/*
 * 函数名称：Bool find(SeqList *seq, ElemType item);
 * 函数作用：查找指定元素；顺序查找，更多查找方法，专题整理；
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool find(SeqList *seq, ElemType item)
{
    int i = 0;

    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (IsEmpty(*seq))
    {
        printf("not found\n");
        return False;
    }

    for (i = 0; i < seq->size; ++i)
    {
        // 说明一下：这里我们用整形去测试，所以比较是否相等用简单的==比较，这里只是学习数据结构的思路
        if (seq->base[i] == item)
        {
            return True;
        }
    }

    printf("not found\n");
    return False;
}

/*
 * 函数名称：Bool Resver(SeqList *seq)；
 * 函数作用：逆置顺序表
 * 函数参数说明：
 *              *seq：顺序表；
 * 函数返回值说明：
 *              成功：成功返回True；
 *              失败：失败返回False；
 * 作者：xiaok
 * 时间：2019-10-11
 *
 * 修改内容：无；
 * 时间：无；
 * 修改者：无；
 * */
Bool Resver(SeqList *seq)
{
    int low = 0;
    int high = 0;
    if (NULL == seq || NULL == seq->base)
    {
        return False;
    }

    if (0 == seq->size)
    {
        return True;
    }

    ElemType tmp;
    high = seq->size - 1;
    while (low < high)
    {
        tmp = seq->base[low];
        seq->base[low++] = seq->base[high];
        seq->base[high--] = tmp;
    }

    return True;
}
