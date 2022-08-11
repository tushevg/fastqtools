#include <iostream>
#include <climits>
#include <zlib.h>
#include <htslib/kseq.h>

KSEQ_INIT(gzFile, gzread)

int main_stats(const int argc, const char *argv[]) {
    gzFile fp;
    kseq_t *seq;
    int l;
    unsigned int seq_count = 0;
    unsigned int seq_total = 0;
    unsigned int seq_min = UINT_MAX;
    unsigned int seq_max = 0;
    
    if (argc == 1) {
        std::cerr << "usage: " << argv[0] << " <in.seq>" << std::endl;
        return 1;
    }

    fp = gzopen(argv[1], "r");
    seq = kseq_init(fp);
    while ((l = kseq_read(seq)) >= 0) {
        seq_count++;
        seq_total += seq->seq.l;
        seq_min = (seq_min < seq->seq.l) ? seq_min : seq->seq.l;
        seq_max = (seq_max < seq->seq.l) ? seq->seq.l : seq_max;
    }
    kseq_destroy(seq);
    gzclose(fp);

    std::cout << "count: " << seq_count << std::endl;
    std::cout << "total: " << seq_total << std::endl;
    std::cout << "seq.min: " << seq_min << std::endl;
    std::cout << "seq.max: " << seq_max << std::endl;
    std::cout << "seq.avg: " << 1.0 * seq_total / seq_count << std::endl;

    return 0;
}