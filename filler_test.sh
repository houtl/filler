rm -rf /tmp/filler_tester
rm -rf /tmp/filler_resources
git clone https://github.com/darklink41/filler_tester.git /tmp/filler_tester
make -C /tmp/filler_tester
git clone https://github.com/houtl/filler.git /tmp/filler_resources
cp -R /tmp/filler_resources/resources .
cp /tmp/filler_tester/filler_tester ./resources
PLAYER=$(cat auteur)
if [ -e "$PLAYER.filler" ]; then
	cp $PLAYER.filler ./resources/players
fi
./resources/filler_tester << EOF
$PLAYER
y
5
y
5
EOF
