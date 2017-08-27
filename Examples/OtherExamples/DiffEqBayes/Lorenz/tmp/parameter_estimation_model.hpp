// Code generated by Stan version 2.16.0

#include <stan/model/model_header.hpp>

namespace parameter_estimation_model_model_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "/Users/rob/.julia/v0.6/Stan/Examples/OtherExamples/DiffEqBayes/Lorenz/tmp/parameter_estimation_model.stan");
    reader.add_event(31, 31, "end", "/Users/rob/.julia/v0.6/Stan/Examples/OtherExamples/DiffEqBayes/Lorenz/tmp/parameter_estimation_model.stan");
    return reader;
}

template <typename T0__, typename T1__, typename T2__, typename T3__>
std::vector<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type>
sho(const T0__& t,
        const std::vector<T1__>& u,
        const std::vector<T2__>& theta,
        const std::vector<T3__>& x_r,
        const std::vector<int>& x_i, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type fun_scalar_t__;
    typedef fun_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        fun_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
            validate_non_negative_index("du", "3", 3);
            vector<fun_scalar_t__> du(3);
            stan::math::initialize(du, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(du,DUMMY_VAR__);


            current_statement_begin__ = 4;
            stan::math::assign(get_base1_lhs(du,1,"du",1), (10.0 * (get_base1(u,2,"u",1) - get_base1(u,1,"u",1))));
            current_statement_begin__ = 4;
            stan::math::assign(get_base1_lhs(du,2,"du",1), ((get_base1(u,1,"u",1) * (28.0 - get_base1(u,3,"u",1))) - get_base1(u,2,"u",1)));
            current_statement_begin__ = 4;
            stan::math::assign(get_base1_lhs(du,3,"du",1), ((get_base1(u,1,"u",1) * get_base1(u,2,"u",1)) - (get_base1(theta,1,"theta",1) * get_base1(u,3,"u",1))));
            current_statement_begin__ = 5;
            return stan::math::promote_scalar<fun_return_scalar_t__>(du);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct sho_functor__ {
    template <typename T0__, typename T1__, typename T2__, typename T3__>
        std::vector<typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type>
    operator()(const T0__& t,
        const std::vector<T1__>& u,
        const std::vector<T2__>& theta,
        const std::vector<T3__>& x_r,
        const std::vector<int>& x_i, std::ostream* pstream__) const {
        return sho(t, u, theta, x_r, x_i, pstream__);
    }
};

class parameter_estimation_model_model : public prob_grad {
private:
    vector<double> u0;
    int T;
    vector<vector<double> > u;
    double t0;
    vector<double> ts;
    vector<double> x_r;
    vector<int> x_i;
public:
    parameter_estimation_model_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    parameter_estimation_model_model(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "parameter_estimation_model_model_namespace::parameter_estimation_model_model";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        validate_non_negative_index("u0", "3", 3);
        context__.validate_dims("data initialization", "u0", "double", context__.to_vec(3));
        validate_non_negative_index("u0", "3", 3);
        u0 = std::vector<double>(3,double(0));
        vals_r__ = context__.vals_r("u0");
        pos__ = 0;
        size_t u0_limit_0__ = 3;
        for (size_t i_0__ = 0; i_0__ < u0_limit_0__; ++i_0__) {
            u0[i_0__] = vals_r__[pos__++];
        }
        context__.validate_dims("data initialization", "T", "int", context__.to_vec());
        T = int(0);
        vals_i__ = context__.vals_i("T");
        pos__ = 0;
        T = vals_i__[pos__++];
        validate_non_negative_index("u", "T", T);
        validate_non_negative_index("u", "3", 3);
        context__.validate_dims("data initialization", "u", "double", context__.to_vec(T,3));
        validate_non_negative_index("u", "T", T);
        validate_non_negative_index("u", "3", 3);
        u = std::vector<std::vector<double> >(T,std::vector<double>(3,double(0)));
        vals_r__ = context__.vals_r("u");
        pos__ = 0;
        size_t u_limit_1__ = 3;
        for (size_t i_1__ = 0; i_1__ < u_limit_1__; ++i_1__) {
            size_t u_limit_0__ = T;
            for (size_t i_0__ = 0; i_0__ < u_limit_0__; ++i_0__) {
                u[i_0__][i_1__] = vals_r__[pos__++];
            }
        }
        context__.validate_dims("data initialization", "t0", "double", context__.to_vec());
        t0 = double(0);
        vals_r__ = context__.vals_r("t0");
        pos__ = 0;
        t0 = vals_r__[pos__++];
        validate_non_negative_index("ts", "T", T);
        context__.validate_dims("data initialization", "ts", "double", context__.to_vec(T));
        validate_non_negative_index("ts", "T", T);
        ts = std::vector<double>(T,double(0));
        vals_r__ = context__.vals_r("ts");
        pos__ = 0;
        size_t ts_limit_0__ = T;
        for (size_t i_0__ = 0; i_0__ < ts_limit_0__; ++i_0__) {
            ts[i_0__] = vals_r__[pos__++];
        }

        // validate, data variables
        check_greater_or_equal(function__,"T",T,1);
        // initialize data variables
        validate_non_negative_index("x_r", "0", 0);
        x_r = std::vector<double>(0,double(0));
        stan::math::fill(x_r,DUMMY_VAR__);
        validate_non_negative_index("x_i", "0", 0);
        x_i = std::vector<int>(0,int(0));
        stan::math::fill(x_i, std::numeric_limits<int>::min());

        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed data

        // validate, set parameter ranges
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        validate_non_negative_index("sigma", "3", 3);
        num_params_r__ += 3;
        validate_non_negative_index("theta", "1", 1);
        num_params_r__ += 1;
    }

    ~parameter_estimation_model_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("sigma")))
            throw std::runtime_error("variable sigma missing");
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        validate_non_negative_index("sigma", "3", 3);
        context__.validate_dims("initialization", "sigma", "vector_d", context__.to_vec(3));
        // generate_declaration sigma
        vector_d sigma(static_cast<Eigen::VectorXd::Index>(3));
        for (int j1__ = 0U; j1__ < 3; ++j1__)
            sigma(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lb_unconstrain(0,sigma);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma: ") + e.what());
        }

        if (!(context__.contains_r("theta")))
            throw std::runtime_error("variable theta missing");
        vals_r__ = context__.vals_r("theta");
        pos__ = 0U;
        validate_non_negative_index("theta", "1", 1);
        context__.validate_dims("initialization", "theta", "double", context__.to_vec(1));
        // generate_declaration theta
        std::vector<double> theta(1,double(0));
        for (int i0__ = 0U; i0__ < 1; ++i0__)
            theta[i0__] = vals_r__[pos__++];
        for (int i0__ = 0U; i0__ < 1; ++i0__)
            try {
            writer__.scalar_unconstrain(theta[i0__]);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable theta: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        // model parameters
        stan::io::reader<T__> in__(params_r__,params_i__);

        Eigen::Matrix<T__,Eigen::Dynamic,1>  sigma;
        (void) sigma;  // dummy to suppress unused var warning
        if (jacobian__)
            sigma = in__.vector_lb_constrain(0,3,lp__);
        else
            sigma = in__.vector_lb_constrain(0,3);

        vector<T__> theta;
        size_t dim_theta_0__ = 1;
        theta.reserve(dim_theta_0__);
        for (size_t k_0__ = 0; k_0__ < dim_theta_0__; ++k_0__) {
            if (jacobian__)
                theta.push_back(in__.scalar_constrain(lp__));
            else
                theta.push_back(in__.scalar_constrain());
        }


        // transformed parameters


        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters

        const char* function__ = "validate transformed params";
        (void) function__;  // dummy to suppress unused var warning

        // model body
        try {
            {
                validate_non_negative_index("u_hat", "T", T);
                validate_non_negative_index("u_hat", "3", 3);
                vector<vector<T__> > u_hat(T, (vector<T__>(3)));
                stan::math::initialize(u_hat, DUMMY_VAR__);
                stan::math::fill(u_hat,DUMMY_VAR__);


                current_statement_begin__ = 25;
                lp_accum__.add(inv_gamma_log<propto__>(sigma, 2, 3));
                current_statement_begin__ = 26;
                lp_accum__.add(normal_log<propto__>(get_base1(theta,1,"theta",1), 2.6665999999999999, 1.0));
                current_statement_begin__ = 27;
                stan::math::assign(u_hat, integrate_ode_rk45(sho_functor__(), u0, t0, ts, theta, x_r, x_i, pstream__));
                current_statement_begin__ = 28;
                for (int t = 1; t <= T; ++t) {

                    current_statement_begin__ = 29;
                    lp_accum__.add(normal_log<propto__>(get_base1(u,t,"u",1), get_base1(u_hat,t,"u_hat",1), sigma));
                }
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("sigma");
        names__.push_back("theta");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(3);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(1);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "parameter_estimation_model_model_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector_d sigma = in__.vector_lb_constrain(0,3);
        vector<double> theta;
        size_t dim_theta_0__ = 1;
        for (size_t k_0__ = 0; k_0__ < dim_theta_0__; ++k_0__) {
            theta.push_back(in__.scalar_constrain());
        }
        for (int k_0__ = 0; k_0__ < 3; ++k_0__) {
            vars__.push_back(sigma[k_0__]);
        }
        for (int k_0__ = 0; k_0__ < 1; ++k_0__) {
            vars__.push_back(theta[k_0__]);
        }

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning



        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters

        // write transformed parameters

        if (!include_gqs__) return;
        // declare and define generated quantities


        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate generated quantities

        // write generated quantities
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "parameter_estimation_model_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= 3; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= 1; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= 3; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= 1; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
    }

}; // model

}

typedef parameter_estimation_model_model_namespace::parameter_estimation_model_model stan_model;
