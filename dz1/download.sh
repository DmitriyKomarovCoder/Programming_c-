wget https://datasets.imdbws.com/title.basics.tsv.gz
wget https://datasets.imdbws.com/title.akas.tsv.gz
wget https://datasets.imdbws.com/title.ratings.tsv.gz
gunzip title.basics.tsv.gz
gunzip title.akas.tsv.gz
gunzip title.ratings.tsv.gz
mkdir dataset
mv title.basics.tsv dataset
mv title.akas.tsv dataset
mv title.ratings.tsv dataset