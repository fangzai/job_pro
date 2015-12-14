""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"一般设置
""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"设置默认编码
set fenc=utf-8
set fencs=utf-8,usc-bom,euc-jp,gbk,gb18030,gb2312,cp936

"不使用vi的键盘模式，而是vim自己的
set nocompatible
"设置行号
set number

"在处理未保存或只读文件的时候，弹出确认
set confirm

"检测文件类型
filetype on 
"载入文件类型插件
filetype plugin on

"设置history文件中记录的行数
set history=1000 

set background=dark
"语法高亮
syntax on

"带有如下符号的单词不要被换行分割
set iskeyword+=_,$,@,%,#,-

set autoindent
set smartindent

"制表符为４
set tabstop=4   
"统一缩进为４
set shiftwidth=4 
set softtabstop=4


set guioptions-=T
set vb t_vb=
set ruler
set nohls
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"文件设置
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
if has("vms")
    set nobackup
else
    set backup
endif
"不要生成swap文件，当buffer被丢弃的时候隐藏
setlocal noswapfile
set bufhidden=hide

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"搜索和匹配
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"高亮显示匹配括号
set showmatch

"在搜索时候，输入的词句的逐字符高亮
set incsearch

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"文本格式和排版
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"自动格式化
set formatoptions=tcrqn

"继承前一行的缩进方式特别适用于多行注释
set autoindent

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"插件的快捷键设置
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"NERDTree
map <F10> :NERDTreeToggle<CR>
