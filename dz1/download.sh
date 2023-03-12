wget https://datasets.imdbws.com/title.basics.tsv.gz
gunzip title.basics.tsv.gz
gunzip title.akas.tsv.gz
gunzip title.ratings.tsv.gz
mkdir dataset
mv title.basics.tsv dataset
mv title.akas.tsv.gz dataset
mv title.ratings.tsv.gz dataset