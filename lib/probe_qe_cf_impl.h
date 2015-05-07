/* -*- c++ -*- */
/* 
 * Copyright 2015 <ARTES Group, Universidad de la República, Uruguay>.
 * http://iie.fing.edu.uy/investigacion/grupos/artes/ingles/index.php3
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_MER_PROBE_QE_CF_IMPL_H
#define INCLUDED_MER_PROBE_QE_CF_IMPL_H

#include <mer/probe_qe_cf.h>

namespace gr {
  namespace mer {

    class probe_qe_cf_impl : public probe_qe_cf
    {
    private:
      int d_nsamples, d_count;
      double d_alpha;
      demapper *d_demapper;
      ste *d_ste;
      mer *d_mer;
      quadrature_error *d_qe; 
      int d_dim_constellation;
      // Message port name
      pmt::pmt_t d_angleh_port;
      pmt::pmt_t d_anglev_port;

     public:
      probe_qe_cf_impl(const std::vector<gr_complex> &symbol_table, double alpha);
      ~probe_qe_cf_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace mer
} // namespace gr

#endif /* INCLUDED_MER_PROBE_QE_CF_IMPL_H */

