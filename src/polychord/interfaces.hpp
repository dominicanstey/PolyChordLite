#ifndef INTERFACES_HPP
#define INTERFACES_HPP
#include <string>

struct Settings
{
    int nDims;
    int nDerived;
    int nlive;
    int num_repeats;
    int nprior;
    bool do_clustering;
    int feedback;
    double precision_criterion;
    double logzero;
    int max_ndead;
    double boost_posterior;
    bool posteriors;
    bool equals;
    bool cluster_posteriors;
    bool write_resume;
    bool write_paramnames;
    bool read_resume;
    bool write_stats;
    bool write_live;
    bool write_dead;
    bool write_prior;
    double compression_factor;
    std::string base_dir;
    std::string file_root;
    int seed;

    Settings(int _nDims=0,int _nDerived=0);
};

void run_polychord( 
        double (*loglikelihood)(double*,int,double*,int), 
        void (*prior)(double*,double*,int), 
        void (*dumper)(int,int,int,double*,double*,double*,double,double), 
        Settings);
void run_polychord( 
        double (*loglikelihood)(double*,int,double*,int),
        void (*dumper)(int,int,int,double*,double*,double*,double,double), 
        Settings);
void run_polychord( 
        double (*loglikelihood)(double*,int,double*,int),
        void (*prior)(double*,double*,int),
        Settings);
void run_polychord(
        double (*loglikelihood)(double*,int,double*,int),
        Settings);  

void run_polychord( 
        double (*loglikelihood)(double*,int,double*,int), 
        void (*setup_loglikelihood)(), 
        std::string);

double default_loglikelihood(double*,int,double*,int); 
void default_prior(double*,double*,int); 
void default_dumper(int,int,int,double*,double*,double*,double,double);

#endif
