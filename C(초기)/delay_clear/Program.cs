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
            {1,1,1,1,1,1,0,1,1,1,1,1 },
            {1,1,1,1,1,1,0,1,1,1,1,1 },
            {1,1,1,1,1,1,1,1,1,1,1,1 },
        };

        static byte[,] colorBackGround = new byte[22,12]{
            {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
        }

        // static byte[,] colorBackGround = new byte[20,10]{
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        //     {7,7,7,7,7,7,7,7,7,7},
        // }

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
        //static byte[,] block_L = new byte[4, 4] {
        //    {0,0,0,0 },
        //    {0,1,0,0 },
        //    {0,1,1,1 },
        //    {0,0,0,0 },
        //};
        static byte[,,,] block = new byte[2, 4, 4, 4]
                {
            {
                { {0, 0, 0, 0},
                  {0, 1, 0, 0},
                  {0, 1, 1, 1},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 0, 0},
                  {0, 1, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 1},
                  {0, 0, 0, 1},
                  {0, 0, 0, 0} },

                { {0, 0, 1, 0},
                  {0, 0, 1, 0},
                  {0, 0, 1, 1},
                  {0, 0, 0, 0} }
            },
            {
                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} }
            },
                };

        static int rotate = 0;

        static ConsoleColor[] colors = (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor));
        static int block_num;
        static int[] block_color = new int[2] { 4, 9 };

        static int x = 5;
        static int y = 5;

        static int count = 0;


        // static은 객체화 하지 않아도 바로 메모리에 올라간다
        static void Main(string[] args)
        {




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
                        if (overlap_check(-1, 0) == 0)
                        {
                            deleteBlock();
                            x--;
                            makeBlock();
                        }

                    }
                    else if (ch == "S") // 아래
                    {
                        if (overlap_check(0, 1) == 0)
                        {

                            deleteBlock();
                            y++;
                            makeBlock();
                        }

                    }
                    else if (ch == "D") // 오른쪽
                    {
                        if (overlap_check(1, 0) == 0)
                        {
                            deleteBlock();
                            x++;
                            makeBlock();
                        }

                    }
                    else if (ch == "R") // 회전
                    {
                        if (overlap_check_rotate() == 0)
                        {

                            deleteBlock();
                            rotate++;
                            if (rotate > 3) rotate = 0;
                            makeBlock();
                        }

                    }
                }

                if (count >= 100)
                {
                    count = 0;
                    if (overlap_check(0, 1) == 0)
                    {
                        deleteBlock();
                        y++;
                        makeBlock();
                    }
                    else
                    {
                        insert_block();
                        print_background_Value();
                        
                        for (int i = 1;i<21 ;i++)
                        {
                            line_check(i);
                        }
                        makeBackGround();
                        print_background_Value();
                        block_num++;
                        if (block_num >= 2)
                        {
                            block_num = 0;
                        }

                        //line_check(19);
                        //line_check(20);

                        x = 3;using System;
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
            {1,1,1,1,1,1,0,1,1,1,1,1 },
            {1,1,1,1,1,1,0,1,1,1,1,1 },
            {1,1,1,1,1,1,1,1,1,1,1,1 },
        };

        static int[,] colorBackGround = new int[22, 12]
        {
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
           {7,7,7,7,7,7,7,7,7,7,7,7},
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

        static byte[,,,] block = new byte[2, 4, 4, 4]
                {
            {
                { {0, 0, 0, 0},
                  {0, 1, 0, 0},
                  {0, 1, 1, 1},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 0, 0},
                  {0, 1, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 1},
                  {0, 0, 0, 1},
                  {0, 0, 0, 0} },

                { {0, 0, 1, 0},
                  {0, 0, 1, 0},
                  {0, 0, 1, 1},
                  {0, 0, 0, 0} }
            },
            {
                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} },

                { {0, 0, 0, 0},
                  {0, 1, 1, 0},
                  {0, 1, 1, 0},
                  {0, 0, 0, 0} }
            }
                };

        static int rotate = 0;

        static ConsoleColor[] colors = (ConsoleColor[])ConsoleColor.GetValues(typeof(ConsoleColor));
        static int block_num;
        static int[] block_color = new int[2] { 4, 9 };

        static int x = 5;
        static int y = 5;

        static int count = 0;


        // static은 객체화 하지 않아도 바로 메모리에 올라간다
        static void Main(string[] args)
        {


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
                        if (overlap_check(-1, 0) == 0)
                        {
                            deleteBlock();
                            x--;
                            makeBlock();
                        }

                    }
                    else if (ch == "S") // 아래
                    {
                        if (overlap_check(0, 1) == 0)
                        {

                            deleteBlock();
                            y++;
                            makeBlock();
                        }

                    }
                    else if (ch == "D") // 오른쪽
                    {
                        if (overlap_check(1, 0) == 0)
                        {
                            deleteBlock();
                            x++;
                            makeBlock();
                        }

                    }
                    else if (ch == "R") // 회전
                    {
                        if (overlap_check_rotate() == 0)
                        {

                            deleteBlock();
                            rotate++;
                            if (rotate > 3) rotate = 0;
                            makeBlock();
                        }

                    }
                }

                if (count >= 100)
                {
                    count = 0;
                    if (overlap_check(0, 1) == 0)
                    {
                        deleteBlock();
                        y++;
                        makeBlock();
                    }
                    else
                    {
                        insert_block();
                        print_background_Value();

                        //print_background_Color();

                        for (int i = 1; i < 21; i++)
                        {
                            line_check(i);
                        }
                        makeBackGround();
                        print_background_Value();
                        block_num++;
                        if (block_num >= block.Length)
                        {
                            block_num = 0;
                        }

                        //line_check(19);
                        //line_check(20);

                        x = 3;
                        y = 3;
                    }


                }

                Thread.Sleep(10);
                count++;

            }



            void makeBlock()
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block[block_num, rotate, j, i] == 1)
                        {
                            Console.ForegroundColor = colors[block_color[block_num]];
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
                        if (block[block_num, rotate, j, i] == 1)
                        {
                            Console.ForegroundColor = colors[7];
                            Console.SetCursorPosition(i + x, j + y);
                            Console.Write("-");
                        }
                    }
                }
            }

            // 블록이 맵을 나가는 것을 방지
            int overlap_check(int tmp_x, int tmp_y)
            {
                int overlap_count = 0;

                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        //if (block[block_num, rotate, j, i] == 1 && background[j + y + tmp_y, i + x + tmp_x] == 1)
                        if (block[block_num, rotate, j, i] == 1 && background[j + y + tmp_y, i + x + tmp_x] == 1)
                        {
                            overlap_count++;
                        }
                    }
                }

                return overlap_count;
            }

            // 블록을 돌렸을 때 맵을 나가는 것을 방지
            int overlap_check_rotate()
            {
                int overlap_count = 0;
                int tmp_rotate = rotate + 1;
                if (tmp_rotate > 3) tmp_rotate = 0;

                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block[block_num, rotate, j, i] == 1 && background[j + y, i + x] == 1)
                        {
                            overlap_count++;
                        }
                    }
                }

                return overlap_count;
            }

            static void makeBackGround()
            {

                int x_pos = 0;
                int y_pos = 0;

                for (int j = 0; j < 22; j++)
                {
                    for (int i = 0; i < 12; i++)
                    {
                        if (background[j, i] == 1)
                        {
                            //Console.ForegroundColor = colors[block_color[block_num]];
                            Console.ForegroundColor = colors[colorBackGround[j, i]];
                            Console.SetCursorPosition(i + x_pos, j + y_pos);
                            Console.Write("*");
                        }
                        else
                        {
                            Console.ForegroundColor = colors[7];
                            Console.SetCursorPosition(i + x_pos, j + y_pos);
                            Console.Write("-");
                        }
                    }
                    Console.WriteLine();
                }
            }

            static void insert_block()
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block[block_num, rotate, j, i] == 1)
                        {
                            background[j + y, i + x] = 1;
                            colorBackGround[j + y, i + x] = block_color[block_num];
                        }
                    }
                }
            }

            static void print_background_Value()
            {
                int xPos = 14;
                int yPos = 0;

                for (int j = 0; j < 22; j++)
                {
                    for (int i = 0; i < 12; i++)
                    {
                        if (background[j, i] == 1)
                        {
                            Console.ForegroundColor = colors[7];
                            Console.SetCursorPosition(i + xPos, j + yPos);
                            Console.Write("1");
                        }
                        else if (background[j, i] == 0)
                        {
                            Console.ForegroundColor = colors[7];
                            Console.SetCursorPosition(i + xPos, j + yPos);
                            Console.Write("0");
                        }
                    }
                }
            }

            static void print_background_Color()
            {
                int xPos = 28;
                int yPos = 0;

                for (int j = 0; j < 22; j++)
                {
                    for (int i = 0; i < 12; i++)
                    {
                        Console.ForegroundColor = colors[7];
                        Console.SetCursorPosition(i + xPos, j + yPos);
                        Console.Write(colorBackGround[j, i]);
                    }
                }
            }

            // 10개가 모두 찼을 때 없애기
            static void line_check(int line_num)
            {
                int count_block = 0;
                for (int i = 0; i < 10; i++)
                {
                    if (background[line_num, i + 1] == 1)
                    {
                        count_block++;
                    }
                }

                if (count_block == 10)
                {
                    for (int j = line_num; j > 1; j--)
                    {
                        for (int i = 0; i < 10; i++)
                        {
                            background[j, i + 1] = background[j - 1, i + 1];
                        }
                    }


                }
            }

        }
    }

}

                        y = 3;
                    }


                }

                Thread.Sleep(10);
                count++;

            }



            void makeBlock()
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block[block_num,rotate, j, i] == 1)
                        {
                            Console.ForegroundColor = colors[block_color[block_num]];
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
                        if (block[block_num,rotate, j, i] == 1)
                        {
                            Console.ForegroundColor = colors[7];
                            Console.SetCursorPosition(i + x, j + y);
                            Console.Write("-");
                        }
                    }
                }
            }

            // 블록이 맵을 나가는 것을 방지
            int overlap_check(int tmp_x, int tmp_y)
            {
                int overlap_count = 0;

                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block[block_num,rotate, j, i] == 1 && background[j + y + tmp_y, i + x + tmp_x] == 1)
                        {
                            overlap_count++;
                        }
                    }
                }

                return overlap_count;
            }

            // 블록을 돌렸을 때 맵을 나가는 것을 방지
            int overlap_check_rotate()
            {
                int overlap_count = 0;
                int tmp_rotate = rotate + 1;
                if (tmp_rotate > 3) tmp_rotate = 0;

                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (block[block_num,rotate, j, i] == 1 && background[j + y, i + x] == 1)
                        {
                            overlap_count++;
                        }
                    }
                }

                return overlap_count;
            }

            static void makeBackGround()
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

            static void insert_block()
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (block[block_num,rotate, j, i] == 1)
                    {
                        background[j + y, i + x] = 1;
                        colorBackGround[j+y,i+x] = block_num;
                    }
                }
            }
        }

            static void print_background_Value()
            {
                int xPos = 14;
                int yPos = 0;

                for (int j = 0; j < 22; j++)
                {
                    for (int i = 0; i < 12; i++)
                    {
                        if (background[j, i] == 1)
                        {
                            Console.ForegroundColor = colors[7];
                            Console.SetCursorPosition(i + xPos, j + yPos);
                            Console.Write("1");
                        }
                        else if (background[j, i] == 0)
                        {
                            Console.ForegroundColor = colors[7];
                            Console.SetCursorPosition(i + xPos, j + yPos);
                            Console.Write("0");
                        }
                    }
                }
            }

            // 10개가 모두 찼을 때 없애기
            static void line_check(int line_num)
            {
                int count_block = 0;
                for (int i = 0; i < 10; i++)
                {
                    if (background[line_num, i + 1] == 1)
                    {
                        count_block++;
                    }
                }

                if (count_block == 10)
                {
                    for (int j = line_num; j >1; j--)
                    {
                        for (int i = 0; i < 10; i++)
                        {
                            background[j, i + 1] = background[j - 1, i + 1];
                        }
                    }


                }
            }

        }
    }

}
