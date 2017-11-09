#include<iostream>
using namespace std;
#include <stack>
struct Pos
{
	int _row;
	int _col;
	Pos()
		:_col(0),
		_row(0)
	{}
};
template<size_t M,size_t N>
class Maze
{
public:
	Maze(int maze[][N])
	{
		for(size_t i=0;i<N;++i)
		{
			for(size_t j=0;j<M;++j)
			{
				_maze[i][j] = maze[i][j];
			}
		}
	}
	bool GetPath(Pos& entry)
	{
		stack<Pos> path;
		path.push(entry);//压栈
		while(!path.empty())
		{
			Pos cur = path.top();
			if(_maze[cur._row][cur._col]==0)
			{
				_maze[cur._row][cur._col] = 2;//标记
			}
			Pos next = cur;
			if(next._row == (M-1))
			{
				return true;
			}
			//探测
			//上
			next._row -= 1;
			if(CheckAccess(next))
			{
				path.push(next);
				continue;
			}
			//右
			next = cur;
			next._col += 1;
			if(CheckAccess(next))
			{
				path.push(next);
				continue;
			}
			//下
			next = cur;
			next._row += 1;
			if(CheckAccess(next))
			{
				path.push(next);
				continue;
			}
			//左
			next = cur;
			next._col -= 1;
			if(CheckAccess(next))
			{
				path.push(next);
				continue;
			}
			
			path.pop();
		}
	return false;	
}
//递归实现
	void GetPath_R(Pos& cur)
	{
		_maze[cur._row][cur._col] = 2;
		if(cur._row == M-1)
		{
			return ;
		}
		Pos next = cur;
		//上
		next._row -= 1;
		if(CheckAccess(next))
		{
			GetPath_R(next);
		}
		next = cur;
		next._row += 1;
		if(CheckAccess(next))
		{
			GetPath_R(next);
		}
		next = cur;
		next._col -= 1;
		if(CheckAccess(next))
		{		
			GetPath_R(next);
		}
		next = cur;
		next._col += 1;
		if(CheckAccess(next))
		{
			GetPath_R(next);
		}
	}

	//找到最短路径
	void GetShortPath(Pos entry,stack<Pos>&path,stack<Pos>&shortPath)
	{
		//递归
		Pos cur = entry;
		path.push(cur);
		_maze[cur._row][cur._col] = 2;
		if(cur._row == M-1)
		{
			if(shortPath.empty()||path.size()<shortPath.size())
			shortPath = path;
			printf("迷宫的一个出口maze[%d][%d]\n",cur._row,cur._col);
			path.pop();
			return;
		}
		Pos next = cur;
		//上
		next._row -= 1;
		if(CheckAccess(next))
		{
			GetShortPath(next,path,shortPath);
		}
		next = cur;
		next._col += 1;
		if(CheckAccess(next))
		{
			GetShortPath(next,path,shortPath);
		}
		next = cur;
		next._row += 1;
		if(CheckAccess(next))
		{
			GetShortPath(next,path,shortPath);
		}
		next = cur;
		next._col -= 1;
		if(CheckAccess(next))
		{		
			GetShortPath(next,path,shortPath);
		}
		
		//最后还没有找到，就pop，回溯
		path.pop();

	}
	//上面的方法虽然可以，但是还是有问题的，当迷宫中含有环状结构的时候就会出现错误
	void GetShortPathE(Pos entry,stack<Pos>&path,stack<Pos>&shortPath)
	{
		//递归
		Pos cur = entry;
		path.push(cur);
		if(entry._row == M-1)
		{
			if(shortPath.empty()||path.size()<shortPath.size())
				shortPath = path;
			printf("迷宫的一个出口maze[%d][%d]\n",cur._row,cur._col);
			//path.pop();
			//return;
		}
		Pos next = cur;
		//上
		next._row -= 1;
		if(CheckIsAccess(next,cur))
		{
			_maze[next._row][next._col] = _maze[cur._row][cur._col]+1;
			GetShortPathE(next,path,shortPath);
		}
		next = cur;
		next._col += 1;

		if(CheckIsAccess(next,cur))
		{			
			_maze[next._row][next._col] = _maze[cur._row][cur._col]+1;
			GetShortPathE(next,path,shortPath);
		}
		next = cur;
		next._row += 1;
		if(CheckIsAccess(next,cur))
		{
			_maze[next._row][next._col] = _maze[cur._row][cur._col]+1;
			GetShortPathE(next,path,shortPath);
		}
		next = cur;
		next._col -= 1;
		if(CheckIsAccess(next,cur))
		{	
			_maze[next._row][next._col] = _maze[cur._row][cur._col]+1;
			GetShortPathE(next,path,shortPath);
		}

		//最后还没有找到，就pop，回溯
		path.pop();

	}
	bool CheckAccess(Pos s)
	{
		if(s._row<M&&s._col<N&&_maze[s._row][s._col]==0)
		{
			return true;
		}
		else 
			return false;
	}
	//如果没走过就直接走，走过的依次升序标记，就是可以让走回头路
	bool CheckIsAccess(Pos next,Pos cur)
	{
		if((cur._row<M&&cur._row>=0)&&(cur._col<N&&cur._col>=0))
		{
			if(_maze[next._row][next._col]==0)
			{
				return true;
			}
			else if(_maze[next._row][next._col]==1)
			{
				return false;
			}
			else 
			{
				return _maze[next._row][next._col]>_maze[cur._row][cur._col]+1;
			}
		}		
		return false;		
	}
	void Print()
	{
		for(size_t i=0;i<N;++i)
		{
			for(size_t j=0;j<M;++j)
			{
				cout<<_maze[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
protected:
	int _maze[M][N];
};

void TestMaze()
{
	int maze[][10] = {{1,1,1,1,1,1,1,1,1,1},
					  {1,1,1,1,1,1,1,1,1,1},
					  {0,0,0,1,1,1,1,1,1,1},
					  {1,1,0,1,1,1,1,1,1,1}, 
					  {1,1,0,0,0,0,1,1,1,1},
					  {1,1,0,1,1,0,1,1,1,1},
					  {1,1,0,0,0,0,1,1,1,1},
					  {1,1,0,1,1,0,1,1,1,1},
					  {1,1,0,1,1,0,1,1,1,1},
				      {1,1,0,1,1,0,1,1,1,1},
					  };
	Maze<10,10> mz(maze);
	Pos entry;
	stack<Pos> path,shortpath;
	entry._row = 2;
	entry._col = 0;
	mz.Print();
	//mz.GetPath(entry);
	//mz.GetPath_R(entry);
	//mz.GetShortPath(entry,path,shortpath);
	mz.GetShortPathE(entry,path,shortpath);
	cout<<shortpath.size()<<endl;

	mz.Print();
}