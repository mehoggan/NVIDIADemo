apt-get clean all
apt-get update
apt-get -y autoremove

apt install -y libncurses5-dev git curl ctags cscope cgdb
apt remove vim vim-runtime gvim
rm -rf ./vim
git clone https://github.com/vim/vim.git
cd vim && ./configure \
  --with-features=huge \
  --enable-multibyte \
	--enable-rubyinterp=yes \
	--enable-pythoninterp=yes \
	--with-python-config-dir=/usr/lib/python2.7/config \
  --enable-gui=no \
  --enable-cscope \
	--prefix=/usr/local && \
  make VIMRUNTIMEDIR=/usr/local/share/vim/vim81 && \
  make install

update-alternatives --install /usr/bin/editor editor /usr/local/bin/vim 1
update-alternatives --set editor /usr/local/bin/vim
update-alternatives --install /usr/bin/vi vi /usr/local/bin/vim 1
update-alternatives --set vi /usr/local/bin/vim

cp ./vimrc /root/.vimrc

mkdir -p /root/.vim/autoload /root/.vim/bundle && \
  curl -LSso /root/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim

cd /root/.vim/bundle && \
  git clone https://github.com/derekwyatt/vim-fswitch.git && \
  git clone https://github.com/junegunn/fzf.vim.git && \
  git clone https://github.com/vim-scripts/mru.vim.git && \
  git clone https://github.com/scrooloose/nerdtree.git && \
  git clone https://github.com/Xuyuanp/nerdtree-git-plugin.git && \
  git clone https://github.com/powerline/powerline.git && \
  git clone https://github.com/vim-syntastic/syntastic.git && \
  git clone https://github.com/majutsushi/tagbar.git && \
  git clone https://github.com/vim-scripts/taglist.vim.git && \
  git clone https://github.com/vim-airline/vim-airline.git && \
  git clone https://github.com/tpope/vim-fugitive.git && \
  git clone https://github.com/airblade/vim-gitgutter.git && \
  git clone https://github.com/vim-utils/vim-man.git && \
  git clone https://github.com/vim-scripts/DoxygenToolkit.vim.git && \
  git clone https://github.com/rdnetto/YCM-Generator.git

cd /root/.vim/bundle && \
  git clone --depth 1 https://github.com/junegunn/fzf.git /root/.fzf && \
  /root/.fzf/install

wget http://releases.llvm.org/7.0.0/clang+llvm-7.0.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz && \
  tar -xvf clang+llvm-7.0.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz

mkdir -p /root/ycm_temp/llvm_root_dir && \
  mv clang+llvm-7.0.0-x86_64-linux-gnu-ubuntu-16.04 /root/ycm_temp/llvm_root_dir

apt-get install -y python-dev && \
  apt-get install -y python3-dev && \
  apt-get install -y ctags && \
  cd /root/.vim/bundle && \
  git clone https://github.com/Valloric/YouCompleteMe.git && \
  cd YouCompleteMe && \
  git submodule update --init --recursive && \
  cd /root && \
  mkdir ycm_build && \
  cd ycm_build && \
  cmake -DPATH_TO_LLVM_ROOT=/root/ycm_temp/llvm_root_dir/clang+llvm-7.0.0-x86_64-linux-gnu-ubuntu-16.04 . \
    /root/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp && \
  cmake --build . --target ycm_core --config Release
