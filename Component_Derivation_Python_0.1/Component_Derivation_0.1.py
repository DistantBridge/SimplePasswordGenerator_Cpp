Input_File_Name='Password_Keywords_No_Derivation.txt'
Output_File_Name = 'Password_Keywords_Addtion_Derivation.txt'

# ----------以上部分用于输入文件名---------

class Letter_Elements_Derivation_Class():
    def __init__(self,Origin_Element,Origin_Grade):

        self.Origin_Element = Origin_Element

        self.Fully_Lowercase = '0'
        self.Fully_Capitalized = '0'
        self.Abbreviation_Lowercase = '0'
        self.Abbreviation_Capitalization = '0'

        self.Origin_Grade = Origin_Grade

    def Fully_Lowercase_Derivation(self): # 完全小写衍生
        self.Fully_Lowercase = self.Origin_Element.lower()

    def Fully_Uppercase_Derivation(self): # 完全大写衍生
        self.Fully_Capitalized = self.Origin_Element.upper()

    def Abbreviation_Lowercase_Derivation(self): # 取大写字母为缩写并转为小写
        Processing_String = ''
        for One_Char in self.Origin_Element:
            if One_Char.isupper() == True:
                Processing_String = Processing_String + One_Char
        Processing_String.lower()
        self.Abbreviation_Lowercase = Processing_String

    def Abbreviation_Capitalization_Derivation(self): # 取大写字母为缩写
        Processing_String = ''
        for One_Char in self.Origin_Element:
            if One_Char.isupper() == True:
                Processing_String = Processing_String + One_Char.lower()
        self.Abbreviation_Capitalization = Processing_String


class Date_Elements_Derivation():
    def __init__(self,Full_Date,Year,YM,MD):
        self.Full_Date = Full_Date
        self.Year = Year
        self.YM = YM
        self.MD = MD

# ----------以上部分用于定义类----------

File_Content_List = []

try:
	#打开文件
    File_Open=open(Input_File_Name,"r")
    print('文件打开成功')
    
    for Line in File_Open.readlines():

        Line=Line.replace('\n','')

        Line=Line.split(',')
		
        File_Content_List.append(Line)            
    File_Open.close()
    print("文件内容为：")
    print(File_Content_List)
except IOError:
    print("文件不存在")

# ----------以上部分用于读取待处理的文件。----------

Letter_Elements_Derivation_List=[] #用于存储各个对象的列表。

List_Len = len(File_Content_List)
Final_Number = eval(File_Content_List[List_Len - 4][0]) # 用于存储最后一组的序号。

Line_Counter = 0
Append_Counter = 0

for Line in File_Content_List:
    Line_Check = ( Line_Counter + 1 ) % 4
    
    Append_Elements = []
    
    if Line_Check == 2: # 若余数为2则为"密码组成值"行。
        for Original_Element in Line: # 列表中每一个原元素的遍历
            if Original_Element.isalpha() == True: #如果全是字母

                Original_Grade = File_Content_List[Line_Counter + 1][0]

                Temp_Class = Letter_Elements_Derivation_Class(Original_Element,Original_Grade)
                Temp_Class.Fully_Lowercase_Derivation()
                Temp_Class.Fully_Uppercase_Derivation()
                Temp_Class.Abbreviation_Lowercase_Derivation()
                Temp_Class.Abbreviation_Capitalization_Derivation()
                
                Letter_Elements_Derivation_List.append(Temp_Class)

        Append_Counter = Append_Counter + 1

    Line_Counter = Line_Counter + 1

# ----------以上部分用于处理读取的文件。----------

with open(Output_File_Name,'w',encoding='UTF-8') as File_Object:

    Print_Counter = 0 

    while Print_Counter <= Append_Counter :

        Final_Number = Final_Number + 1
        File_Object.write(str(Final_Number))
        File_Object.write(',')
        File_Object.write('\n')

        Write1= str(Letter_Elements_Derivation_List[Print_Counter].Fully_Lowercase)
        File_Object.write(Write1)
        File_Object.write(',')
        Write2 = str(Letter_Elements_Derivation_List[Print_Counter].Fully_Capitalized)
        File_Object.write(Write2)
        File_Object.write(',')
        Write3 = str(Letter_Elements_Derivation_List[Print_Counter].Abbreviation_Lowercase)
        File_Object.write(Write3)
        File_Object.write(',')
        Write4 = str(Letter_Elements_Derivation_List[Print_Counter].Abbreviation_Capitalization)
        File_Object.write(Write4)
        File_Object.write('\n')

        Write5 = str(Letter_Elements_Derivation_List[Print_Counter].Origin_Grade)
        File_Object.write(Write5)
        File_Object.write(',')
        File_Object.write('\n')

        Print_Counter = Print_Counter + 1

