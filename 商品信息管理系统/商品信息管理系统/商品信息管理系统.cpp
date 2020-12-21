#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <cstdlib>
using namespace std;



//商品类
class goods {
public:
    void set();
    string GetNum();
    string GetName();
    string GetPdr();
    void print(int);
    //输出所有信息
    void DeleteData();
private:
    string  g_num,
        //商品编号
        g_price,
        //商品价格
        g_date,
        //生产日期
        g_name,
        //商品名
        g_pdr,
        //生产厂家
        g_stock;
    //剩余库存
};




//查找
void Search();

//输出全部商品
void PrintAllData();

//添加商品信息
void Add();

//更改商品信息
void Change(string a);

//删除商品信息
void Delete(string a);

//主菜单
void start();
//退出
void Exit();



//全局变量
int length = 10;                     //动态数组初始长度
goods* Goods = new goods[length];    //构建动态数组
int NumOfData = 0;                   //记录存储数据个数




//主函数
int main()
{
    start();
}



//函数定义
void Search()
{
    string a;

    cout << "请问阁下要找什么呢:";
    cin >> a;
    for (size_t i = 0; i < NumOfData; i++)
    {
        if (Goods[i].GetNum() == a || Goods[i].GetName() == a || Goods[i].GetPdr() == a) {
            cout << "找到了!是这些!"
                << endl;

            if (Goods[i].GetNum() == a || Goods[i].GetName() == a)
            {
                Goods[i].print(0);
            }

            //一个生产厂家有多个产品,需要多次查找找出所有信息
            else if (Goods[i].GetPdr() == a)
            {
                for (size_t j = i; j < NumOfData; j++)
                {
                    if (Goods[j].GetPdr() == a)
                    {
                        Goods[j].print(j - i);
                    }
                }
            }
            break;
        }
        else
        {
            if (i == NumOfData - 1)
                cout << "没有找到呢!请阁下检查您输入的内容!即将返回主菜单..."
                << endl;
        }
    }


    //暂停,按任意键继续
    system("pause");

    //返回菜单界面
    return;
}




void PrintAllData()
{
    if (Goods[0].GetName() == "已删除")
    {
        cout << setw(8) << "编号" << "|" << setw(8) << "名称" << "|" << setw(8) << "生产厂家" << "|" << setw(8) << "价格" << "|" << setw(8) << "生产日期" << "|" << setw(8) << "库存" << endl
            << "-----------------------------------------------------" << endl;
    }
    for (size_t i = 0; i < NumOfData; i++)
    {
        if (Goods[i].GetName() != "已删除")
        {
            Goods[i].print(i);
        }

    }
}



void Add()
{
    //数据个数加一,检测是否填满判断是否需要对数组扩容
    NumOfData++;
    if (NumOfData >= length)
    {
        goods* temp = new goods[length * 2];
        for (int j = 0; j < length; j++)
        {
            temp[j] = Goods[j];
        }
        delete[]Goods;
        Goods = temp;
        length *= 2;
    }


    goods p;
    p.set();
    Goods[NumOfData - 1] = p;
    cout << "添加完成 !"
        << endl;
    system("pause");


}



void Change(string a)
{
    for (size_t i = 0; i < NumOfData; i++)
    {
        if (Goods[i].GetNum() == a || Goods[i].GetName() == a) {
            Goods[i].set();
            cout << "太棒了!阁下想要修改的信息修改成功了!";
            system("pause");
        }
        return;
    }
    cout << "没找到想要修改的数据" << endl;
}




void Delete(string a)
{
    for (size_t i = 0; i < NumOfData; i++)
    {
        if (Goods[i].GetName() == a || Goods[i].GetNum() == a)
        {
            Goods[i].DeleteData();
            cout << "商品信息已删除!";
            system("pause");
            return;
        }
    }
    cout << "没找到想要删除的数据" << endl;

}




void start()
{
    //用户输入的字符,用于确认选择
    char chos = '\0';

    //清空屏幕
    system("cls");

    //欢迎界面
    cout << "欢迎使用本商品信息管理系统!请问您要?"
        << endl
        << "1.添加新的商品信息"
        << endl
        << "2.修改某件商品信息"
        << endl
        << "3.查找商品"
        << endl
        << "4.浏览全部商品信息"
        << endl
        << "5.删除某件商品信息"
        << endl
        << "6.没事了,退出"
        << endl;

    //读取键盘输入信息(这个函数不需要回车)
    chos = _getch();

    //用户输入信息
    string temp;

    //关闭欢迎界面
    system("cls");


    //判断输入信息执行不同操作
    switch (chos) {
    case '1':
        Add();
        break;

    case '2':
        cout << "请输入要更改的商品名称或编号:";
        cin >> temp;
        Change(temp);

        break;

    case '3':
        Search();

        break;

    case '4':
        PrintAllData();
        system("pause");
        break;

    case '5':
        cout << "请输入要删除的商品名称或编号:";
        cin >> temp;
        Delete(temp);

        break;

    case '6':
        Exit();

    default:
        break;
    }


    start();
}




void Exit()
{
    cout << "期待您的再次使用!再见!";
    exit(0);
}




void goods::set()
{
    cout << "请输入商品信息....";
    cout << endl;

    cout << "请输入商品名称....";
    cin >> g_name;

    cout << "请输入商品编号....";
    cin >> g_num;

    cout << "请输入商品价格....";
    cin >> g_price;

    cout << "请输入生产厂家....";
    cin >> g_pdr;


    cout << "请输入生产日期....";
    cin >> g_date;

    cout << "请输入剩余库存....";
    cin >> g_stock;
}




string goods::GetNum()
{
    return g_num;
}




string goods::GetName()
{
    return g_name;
}




string goods::GetPdr()
{
    return g_pdr;
}




void goods::print(int a)
{
    if (!a)//a为0时输出表头
    {
        cout << setw(8)   << "编号" << "|"<< setw(8)<< "名称"<< "|"<< setw(8)<< "生产厂家"<< "|"<< setw(8)<< "价格"<< "|"<< setw(8)<< "生产日期"<< "|"<< setw(8)<< "库存"<< endl
            << "-----------------------------------------------------" << endl;
    }
    cout << setw(8)<< g_num<< "|"<< setw(8)<< g_name<< "|"<< setw(8)<< g_pdr<< "|"<< setw(8)<< g_price<< "|"<< setw(8)<< g_date<< "|"<< setw(8)<< g_stock << endl;
}



void goods::DeleteData()
{
    this->g_name = "已删除";
}


