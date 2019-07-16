#include "pch.h"
#include "FileIO.h"

#pragma region Constructors
FileIO::FileIO()
{
}
FileIO::~FileIO()
{
}
#pragma endregion

#pragma region Methods
void FileIO::WriteLines(string fileName, vector<string>lines) {

	ofstream stream(&fileName[0]);
	for (string line : lines)
		stream.write(line.c_str(), line.size());
	stream.close();
}
void FileIO::WriteLinesLn(string fileName, vector<string>lines) {
	ofstream stream(&fileName[0]);
	for (string line : lines) {
		line += '\n';
		stream.write(line.c_str(), line.size());
	}
	stream.close();
}
void FileIO::Append(string filename, vector<string>lines) {
	vector<string>currentLines = ReadLines(filename);
	currentLines.insert(currentLines.end(), lines.begin(), lines.end());
	WriteLines(filename, currentLines);
}
vector<string> FileIO::ReadLines(string fileName)
{
	fstream stream(&fileName[0]);
	string line;
	vector<string> result;
	while (getline(stream, line))
		result.push_back(line);
	stream.close();
	return result;
}
vector<vector<string>> FileIO::ReadMatrix(string fileName)
{
	StrHelper strHelper = StrHelper();
	vector <vector<string>> matrix;
	vector<string> lines = ReadLines(fileName);
	for (size_t i = 0; i < lines.size(); i++)
		matrix.push_back(strHelper.Split(lines[i], ' '));
	return matrix;
}
FILE* FileIO::OpenRead(string fileName) {
	FILE* file = NULL;
	fopen_s(&file, fileName.c_str(), "r");
	return file;
}
string FileIO::ReadAllText(string fileName) {
	string res = "";
	vector<string> lines = ReadLines(fileName);
	for (int i = 0; i < lines.size(); i++)
		res += lines[i];
	return res;
}
FILE* FileIO::OpenWrite(string fileName) {
	FILE* file = NULL;
	fopen_s(&file, fileName.c_str(), "w");
	return file;
}
void FileIO::Close(FILE* file) {
	if (file != NULL)
		fclose(file);
}
#pragma region Remove comments
/// <summary>
/// ���������� ������ � �������� ����
/// </summary>
/// <param name="c">������� ������</param>
/// <param name="input">������� ����</param>
/// <param name="output">�������� ����</param>
/// <returns></returns>
char PutGetNext(char c, FILE* input, FILE* output) {
	fputc(c, output);
	return fgetc(input);
}
void FileIO::RemoveComments(string inFile, string outFile) {
	FILE* input = OpenRead(inFile);
	FILE* output = OpenWrite(outFile);
	if (!input)
	{
		printf("\n�� ������� ������� ���� %s ��� ������", inFile.c_str());
		fclose(output);
	}
	char cur = fgetc(input);

	if (output)
	{
		if (cur != EOF)
		{
			while (cur != EOF)
			{
				if ((cur != '/') && (cur != '\"') && (cur != '\''))
					cur = PutGetNext(cur, input, output);
				else
				{
					if ((cur != '\"') && (cur != '\''))
					{
						cur = fgetc(input);
						if (cur == '/' || cur == '*')
						{
							if (cur == EOF)
								break;
							if (cur == '/')
							{
								cur = fgetc(input);
								while (cur != '\n')
								{
									if (cur == EOF)
										break;
									if (cur == '\\')
									{
										cur = fgetc(input);
										cur = fgetc(input);
									}
									else
										cur = fgetc(input);
								}
							}
							else
							{
								cur = fgetc(input);
								while (cur)
								{
									if (cur == EOF)
										break;
									if (cur == '*')
									{
										cur = fgetc(input);
										if (cur == '/')
										{
											cur = fgetc(input);
											break;
										}
									}
									else
										cur = fgetc(input);
								}
							}
						}
						else
							fputc('/', output);
					}
					else
					{
						if (cur == '\"')
						{
							cur = PutGetNext(cur, input, output);
							while (cur != '\"')
							{
								if (cur == EOF)
									break;
								if (cur == '\\')
								{
									cur = PutGetNext(cur, input, output);
									cur = PutGetNext(cur, input, output);
									if (cur == '\"')
										break;
								}
								else
								{
									if (cur != '\n')
										cur = PutGetNext(cur, input, output);
									else
										break;
								}
							}
							cur = PutGetNext(cur, input, output);
						}
						else
						{
							cur = PutGetNext(cur, input, output);
							while (cur != '\'')
							{
								if (cur == EOF || cur == '\'')
									break;
								if (cur == '\\')
									cur = PutGetNext(cur, input, output);
								if (cur != '\n')
									cur = PutGetNext(cur, input, output);
								else
									break;
							}
							cur = PutGetNext(cur, input, output);
						}
					}
				}
			}
		}
	}
	else
		printf("\n�� ������� ������� ���� %s ��� ������", outFile.c_str());
	printf("\n����������� �� ����� %s �������, �������� ����: %s.\n", inFile.c_str(), outFile.c_str());
	Close(input);
	Close(output);
}
void FileIO::RemoveComments(FILE* in, FILE* out)
{
	if (in && out)
	{
		//������� � ��������� �������
		char buff[2] = { '\0','\0' };
		//������� ( ���������� ����� ��� ���)
		char ignore = '\0';
		//������� ����
		while ((buff[0] = fgetc(in)) != EOF)
		{
			// �������� �� ������ ����������� ��� ������
			if (!ignore)
			{
				//���� ������� ����������� "//"
				if ((buff[1] == '/') && (buff[0] == '/'))
					ignore = '/';
				//���� ������� ����������� "/*"
				else if ((buff[1] == '/') && (buff[0] == '*'))
					ignore = '*';
				//���������� ������ �����,�� �� ������������ ��������
				else if (((buff[1] != '\'') && (buff[0] == '"')) &&
					((buff[1] != '\\') && (buff[0] == '"')))
				{
					fputc(buff[1], out);
					fputc(buff[0], out);
					ignore = '"';
				}
				//������� �����, ���� ����� ����
				if (ignore)
				{
					buff[0] = '\0';
					buff[1] = '\0';
				}
			}
			//�������� �� �������, ������� �������� ����
			switch (ignore)
			{
				//���� "//" ���� ����� ������
			case '/':
				if (buff[1] == '\n')
					ignore = '\0';
				break;
				//���� "/*", �� ���� "*/"
			case '*':
				if ((buff[1] == '*') && (buff[0] == '/'))
				{
					buff[0] = '\0';
					buff[1] = '\0';
					ignore = '\0';
				}
				break;
				//���� ���������� ������ ���� '"'
			case '"':
				if ((buff[1] != '\\') && (buff[0] == '"'))
				{
					fputc(buff[1], out);
					fputc(ignore, out);
					ignore = '\0';
					buff[0] = '\0';
					buff[1] = '\0';
				}
				break;
			default:
				break;
			}
			//����� ���������� �����
			if (ignore == '"') {
				if (buff[1] != '\0')
					fputc(buff[1], out);
			}
			//���� ��� ����� ��������, �� ����� ������ � ���� 
			if ((!(ignore)) && (buff[1]))
				fputc(buff[1], out);
			//�������� ��������
			//������� ���������� ���������
			buff[1] = buff[0];
		}
		//�������� ������� �� ���������� ����������� ����������� ��� ������
		if (ignore)
			fprintf(stderr, "���������� ���� ��� ������\n");
		//���������� ��������� ������
		fputc(buff[1], out);
	}
}
#pragma endregion
#pragma endregion