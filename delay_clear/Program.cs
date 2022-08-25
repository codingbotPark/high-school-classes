using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Threading;

namespace ConsoleApp2
{
    // 클래스는 메모리에 아직 올리지 않은 상태이다,
    // 이런 클래스를 메모리에 올리는 것을 객체 -> '객체화 하다' 라고 한다

    class Program
    {
        // static으로 해서 메모리에 올라갈 수 있도록 해줘야 main에서 접근할 수 있다
        static int counter = 0;

        //static byte[] num_byte = new byte[8] { 0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38 };
        static byte[] num_byte = new byte[8] { 0x00, 0x38, 0x44, 0x4c, 0x54, 0x64, 0x44, 0x38 };

        static byte[,] num_byte_2 = new byte[2, 8] { { 0x00, 0x38, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7c }, { 0x00, 0x38, 0x44, 0x04, 0x18, 0x04, 0x44, 0x38 } };

        static byte[,] background = new byte[22, 12]
        {
            {1,1,1,1,1,1,1,1,1,1,1,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,0,0,0,0,0,0,0,0,0,0,1 },
            {1,1,1,1,1,1,1,1,1,1,1,1 },
        };

        static byte[,] num_byte_3 = new byte[10, 8] {
            { 0x00,0x38,0x44,0x4c,0x54,0x64,0x44,0x38}, // 0
                {0x00,0x10,0x30,0x50,0x10,0x10,0x10,0x7c}, // 1
                {0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c},
                { 0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38},
        { 0x00,0x08,0x18,0x28,0x48,0x7c,0x08,0x08},
        { 0x00,0x7c,0x40,0x78,0x04,0x04,0x44,0x38},
        { 0x00,0x38,0x40,0x40,0x78,0x44,0x44,0x38},
        { 0x00,0x7c,0x04,0x08,0x10,0x20,0x20,0x20},
        { 0x00,0x38,0x44,0x44,0x38,0x44,0x44,0x38},
        { 0x00,0x38,0x44,0x44,0x3c,0x04,0x44,0x38},

            };

        // 테트리스의 블록 만들기
        static byte[,] block_L = new byte[4, 4] {
            {0,0,0,0 },
            {0,1,0,0 },
            {0,1,1,1 },
            {0,0,0,0 },
        };

        static int x = 5;
        static int y = 5;

        static int count = 0;

        // static은 객체화 하지 않아도 바로 메모리에 올라간다
        static void Main(string[] args)
        {


            //// 테트리스 블록 하나 출력
            //for (int j = 0; j < 4; j++)
            //{
            //    for (int i = 0; i < 4; i++)
            //    {
            //        if (block_L[j, i] == 1)
            //        {
            //            Console.Write("*");
            //        }
            //        else
            //        {
            //            Console.Write("-");
            //        }
            //    }
            //    Console.WriteLine();
            //}

            ConsoleKeyInfo key_value;
            String ch;


            makeBackGround();

            while (true)
            {

                if (Console.KeyAvailable)
                {   
                    // true를 줘서 키보드 입력이 출력되지 않게 한다
                    key_value = Console.ReadKey(true);
                    ch = key_value.Key.ToString();

                    // 블록 이동
                    if (ch == "A") // 왼쪽
                    {
                        if (overlap_check(-1,0) == 0)
                        {
                            deleteBlock();
                            x--;
                            makeBlock();
                        }
                        
                    } 
                    else if(ch == "S") // 아래
                    {
                        if (overlap_check(0, 1) == 0)
                        {

                            deleteBlock();
                            y++;
                            makeBlock();
                        }

                    }
                    else if(ch == "D") // 오른쪽
                    {
                        if (overlap_check(1, 0) == 0)
                        {
                            deleteBlock();
                            x++;
                            makeBlock();
                        }

                    }
                }

                if (count > 100)
                {
                    count = 0;

                    if (overlap_check(0, 1) == 0)
                    {
                        deleteBlock();
                        y++;
                        makeBlock();
                    }
                }

                Thread.Sleep(10);
                count++;

            }

            void makeBackGround()
            {

                int x_pos = 0;
                int y_pos = 0;

                for (int j = 0; j < 22; j++)
                {
                    for (int i = 0; i < 12; i++)
                    {
                        if (background[j, i] == 1)
                        {
                            Console.SetCursorPosition(i + x_pos, j + y_pos);
                            Console.Write("*");
                        }
                        else
                        {
                            Console.SetCursorPosition(i + x_pos, j + y_pos);
                            Console.Write("-");
                        }
                    }
                    Console.WriteLine();
                }
            }

            void makeBlock()
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block_L[j, i] == 1)
                        {
                            // setCursorPointer는 c에서의 gotoXY와 같다
                            // 기준은 0,0이 왼쪽 위이다
                            Console.SetCursorPosition(i + x, j + y);
                            Console.Write("*");

                        } // 원래 else가 있었는데, background가 출력되고 출력을 하기 때문에 그냥 else일 때는 탈출
                    }
                    Console.WriteLine();
                }
            }

                void deleteBlock()
                {
                    for (int j = 0; j < 4; j++)
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            if (block_L[j, i] == 1)
                            {
                                Console.SetCursorPosition(i+x, j + y);
                                Console.Write("-");
                            }
                        }
                    }
                }

            int overlap_check(int tmp_x, int tmp_y)
            {
                int overlap_count = 0;

                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block_L[j,i] == 1 && background[j +y+tmp_y, i+x+tmp_x] == 1)
                        {
                            overlap_count++;
                        }
                    }
                }

                return overlap_count;
            }


            //byte num = 0x23;
            //byte num1 = 0x37;

            //// 줄 내리기
            //Console.WriteLine("Hello World");
            //// delay
            //Thread.Sleep(1000);
            //// console 클리어
            //Console.Clear();
            //Console.WriteLine("Hi")
            // scanf와 비슷함
            //Console.ReadLine();

            //// 두 자리수 카운팅
            //for (int i = 0; i < 10; i++)
            //{
            //    for (int j = 0; j < 10; j++)
            //    {
            //        // 10의 자리 수
            //        for (int u = 0; u < 8; u++)
            //        {
            //            for (int w = 0; w < 8; w++)
            //            {
            //                if ((num_byte_3[i, u] & (0x80 >> w)) > 0)
            //                {
            //                    Console.Write("*");
            //                }
            //                else
            //                {
            //                    Console.Write("-");
            //                }
            //            }
            //            for (int w = 0; w < 8; w++)
            //            {
            //                if ((num_byte_3[j, u] & (0x80 >> w)) > 0)
            //                {
            //                    Console.Write("*");
            //                }
            //                else
            //                {
            //                    Console.Write("-");
            //                }
            //            }
            //            Console.WriteLine();
            //        }
            //        Thread.Sleep(100);
            //        Console.Clear();
            //    }
            //}



            // 2, 3 만 
            //while (true)
            //{
            //    for (int j = 0; j < 8; j++)
            //    {
            //        for (int i = 0; i < 8; i++)
            //        {
            //            if ((num_byte_2[0, j] & (0x80 >> i)) > 0)
            //            {
            //                Console.Write("*");
            //            }
            //            else
            //            {
            //                Console.Write("-");
            //            }
            //        }
            //        Console.WriteLine();
            //    }
            //    Thread.Sleep(1000);
            //    Console.Clear();
            //    for (int j = 0; j < 8; j++)
            //    {
            //        for (int i = 0; i < 8; i++)
            //        {
            //            if ((num_byte_2[1, j] & (0x80 >> i)) > 0)
            //            {
            //                Console.Write("*");
            //            }
            //            else
            //            {
            //                Console.Write("-");
            //            }
            //        }
            //        Console.WriteLine();
            //    }
            //    Thread.Sleep(1000);
            //    Console.Clear();
            //}



            // 숫자 출력
            //for (int j = 0; j < 8; j++)
            //{
            //    for (int i = 0; i < 8; i++)
            //    {
            //        if ((num_byte[j] & 0x80 >> i) > 0)
            //        {
            //            Console.Write("*");
            //        }
            //        else
            //        {
            //            Console.Write("-");
            //        }
            //    }
            //    Console.WriteLine();
            //}


            //// 0000 0000
            //// 에서 왼쪽 끝은 msb, 오른쪽 끝은 lsb
            //for (int i = 0; i < 8; i++)
            //{
            //    // 비트 연산으로 1이 있는 자리를 별로 만들기
            //    if ((num & 0x80 >> i) > 0)
            //    {
            //        Console.Write("*");
            //    }
            //    else
            //    {
            //        Console.Write("-");
            //    }
            //}
            //Console.WriteLine();
            //for (int i = 0; i < 8; i++)
            //{
            //    // 비트 연산으로 1이 있는 자리를 별로 만들기
            //    if ((num1 & 0x80 >> i) > 0)
            //    {
            //        Console.Write("*");
            //    }
            //    else
            //    {
            //        Console.Write("-");
            //    }
            //}



            //// 숫자 카운팅
            //while (true)
            //{
            //    Console.WriteLine(counter);
            //    counter++;
            //    Thread.Sleep(1000);
            //    Console.Clear();
            //}

        }
    }
}


//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

//using System.Threading;

//namespace ConsoleApp2
//{
//    class Program
//    {


//        static void Main(string[] args)
//        {
//            int i, j;
//            int num = 0

//            // new 키워드를 사용하면 heap 영역에 들어가게 된다
//            byte[,] font = new byte[2, 8] {
//                {0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x7c},
//                {0x00,0x38,0x44,0x04,0x18,0x04,0x44,0x38}
//            };

//            Console.Clear();

//            while (true)
//            {

//                for (j = 0; j < 8; j++)
//                {
//                    for (i = 0; i < 8; i++)
//                    {
//                        if ((font[num, j] & (0x01 << (7 - i))) > 0)
//                        {
//                            Console.Write("*");
//                        }
//                        else
//                        {
//                            Console.Write(" ");
//                        }
//                    }

//                    Console.WriteLine("");
//                }
//                num++;
//                if (num > 1) num = 0;

//                Thread.Sleep(1000);
//                Console.Clear();

//            }

//        }
//    }
//}
