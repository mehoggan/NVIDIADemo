execute pathogen#infect()
syntax on
filetype plugin indent on

autocmd QuickFixCmdPost *grep* cwindow

:set rtp+=/usr/local/opt/fzf
:set expandtab
:set tabstop=2
:set shiftwidth=2
:set backspace=2
:set hlsearch
:set vb !
:set statusline+=%#warningmsg#
:set statusline+=%{SyntasticStatuslineFlag()}
:set statusline+=%*
:set nocompatible
:set autochdir
:set encoding=utf-8

:map <F2> :NERDTreeToggle<CR>
:map <F3> :TagbarToggle<CR>
:map <F4> :FZF<CR>
:map <F5> :set spell! spelllang=en_us<CR>
:map <F6> :!ls<CR>:cd

if has("gui_macvim")
  :set background=dark
  :colorscheme slate
  nnoremap <silent> <C-Right> <c-w>l
  nnoremap <silent> <C-Left> <c-w>h
  nnoremap <silent> <C-Up> <c-w>k
  nnoremap <silent> <C-Down> <c-w>j
endif

if exists('+colorcolumn')
  set colorcolumn=79
else
  highlight OverLength ctermbg=red ctermfg=white guibg=#592929
  match OverLength /\%79v.\+/
endif

:let g:NERDTreeWinSize = 35
:let g:NERDTreeDirArrows = 0
:let NERDTreeIgnore = ['AUTHORS$', 'ChangeLog$', 'missing.*',
      \ 'depcomp.*', 'config\.guess', 'config\.h\.in', 'config\.status',
      \ 'install-sh$', 'NEWS$', 'stamp-h1$', 'ar-lib$', 'autom4te.cache$',
      \ 'ar-lib$', 'auto4mt\.cache$', 'compile$', 'config\.log$',
      \ 'config.sub$', 'libtool$', 'missing$', 'README$',
      \ 'ltmain\.sh$', '\.o$', '\.lo$', '\.out', '\.S', '\.pyc', 'tags.*' ]
:let g:syntastic_always_populate_loc_list = 1
:let g:syntastic_auto_loc_list = 1
:let g:syntastic_check_on_open = 1
:let g:syntastic_check_on_wq = 0
:let g:syntastic_python_pylint_post_args="--max-line-length=79"
:let g:gitgutter_terminal_reports_focus=0
