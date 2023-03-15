wget https://datasets.imdbws.com/title.basics.tsv.gz
wget https://datasets.imdbws.com/title.akas.tsv.gz
wget https://datasets.imdbws.com/title.ratings.tsv.gz
gunzip *.tsv.gz
mkdir dataset
mv *.tsv dataset