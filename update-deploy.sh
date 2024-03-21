WWW_DIR="/opt/1panel/apps/openresty/openresty/www/sites/plan.xiyoulinux.com/index"

git pull
sudo pip install -r requirements.txt
mkdocs build
sudo rm -rf $WWW_DIR
sudo cp -r site $WWW_DIR