# standard imports
import unittest

# third party imports

# local imports
from ACEtk import PhotoAtomicPrincipalCrossSectionBlock

class Test_ACEtk_PhotoAtomicPrincipalCrossSectionBlock( unittest.TestCase ) :
    """Unit test for the PhotoAtomicPrincipalCrossSectionBlock class."""

    chunk = [ -6.907755278982E+00, -6.502290170874E+00, -6.214608098422E+00, -5.809142990314E+00,
              -5.521460917862E+00, -5.298317366548E+00, -5.115995809754E+00, -4.828313737302E+00,
              -4.605170185988E+00, -4.199705077880E+00, -3.912023005428E+00, -3.506557897320E+00,
              -3.218875824868E+00, -2.995732273554E+00, -2.813410716760E+00, -2.525728644308E+00,
              -2.302585092994E+00, -1.897119984886E+00, -1.609437912434E+00, -1.203972804326E+00,
              -9.162907318742E-01, -6.931471805600E-01, -5.108256237660E-01, -2.231435513142E-01,
                                0,  2.176149178151E-02,  4.054651081082E-01,  6.931471805599E-01,
               7.149086723415E-01,  1.098612288668E+00,  1.386294361120E+00,  1.609437912434E+00,
               1.791759469228E+00,  2.079441541680E+00,  2.302585092994E+00,  2.708050201102E+00,
               2.995732273554E+00,  3.401197381662E+00,  3.688879454114E+00,  3.912023005428E+00,
               4.094344562222E+00,  4.382026634674E+00,  4.605170185988E+00, -2.474115088710E+00,
              -1.801615884491E+00, -1.395274562701E+00, -9.619368437599E-01, -7.605035347293E-01,
              -6.564816521895E-01, -5.973280393893E-01, -5.379604661733E-01, -5.121031060658E-01,
              -4.951622704106E-01, -4.996615083952E-01, -5.236170868157E-01, -5.519549571767E-01,
              -5.804883624210E-01, -6.082473646805E-01, -6.606006131276E-01, -7.087177755509E-01,
              -8.132559185667E-01, -9.004223039898E-01, -1.039979295888E+00, -1.149677188087E+00,
              -1.240439712683E+00, -1.318224582219E+00, -1.447723056117E+00, -1.554102548229E+00,
              -1.565234595395E+00, -1.761517405317E+00, -1.920163458054E+00, -1.933037974696E+00,
              -2.160044406212E+00, -2.341411164029E+00, -2.488070449328E+00, -2.611526212807E+00,
              -2.812417876456E+00, -2.972959551555E+00, -3.273902395055E+00, -3.493770011977E+00,
              -3.811227895393E+00, -4.041090092197E+00, -4.221732578372E+00, -4.370691125010E+00,
              -4.608126551734E+00, -4.794460770140E+00, -5.438809818403E-01, -6.963824082700E-01,
              -8.816695225475E-01, -1.286177569785E+00, -1.670840023917E+00, -2.009497655884E+00,
              -2.303961039174E+00, -2.792755511835E+00, -3.189195670767E+00, -3.941353983624E+00,
              -4.493199565291E+00, -5.286155621289E+00, -5.854953099262E+00, -6.298223430325E+00,
              -6.661192120127E+00, -7.234899160315E+00, -7.680387322840E+00, -8.490556129031E+00,
              -9.065634150977E+00, -9.876327742081E+00, -1.045166550264E+01, -1.089788037630E+01,
              -1.126257928307E+01, -1.183793979483E+01, -1.228421366256E+01, -1.232773629793E+01,
              -1.309513739115E+01, -1.367044098687E+01, -1.371396398204E+01, -1.448137141933E+01,
              -1.505675956723E+01, -1.550303434392E+01, -1.586772611339E+01, -1.644309890848E+01,
              -1.688938601110E+01, -1.770029298013E+01, -1.827562847225E+01, -1.908666032844E+01,
              -1.966212006760E+01, -2.010848568546E+01, -2.047323890380E+01, -2.104887271593E+01,
              -2.149558177385E+01,  2.449279472145E+00,  1.084175240870E+00,  1.079571415050E-01,
              -1.277619344494E+00, -2.265289308250E+00, -3.033641846627E+00, -3.662432284099E+00,
              -4.655516560425E+00, -5.426150738058E+00, -6.826175291990E+00, -7.816822165767E+00,
              -9.208342369314E+00, -1.019143632722E+01, -1.094988696976E+01, -1.156738059480E+01,
              -1.253596656679E+01, -1.328194544723E+01, -1.462406859004E+01, -1.556478541559E+01,
              -1.687141755455E+01, -1.778410391488E+01, -1.848287534755E+01, -1.904747854397E+01,
              -1.992620919300E+01, -2.059751463164E+01, -2.063568369061E+01, -2.130868929642E+01,
              -2.181328515120E+01, -2.184419873302E+01, -2.238927410087E+01, -2.274935620313E+01,
              -2.302861474576E+01, -2.323781965288E+01, -2.356790925614E+01, -2.382395870614E+01,
              -2.424700380348E+01, -2.454714061185E+01, -2.497013240600E+01, -2.527026145888E+01,
              -2.550312279898E+01, -2.569333036808E+01, -2.599348177338E+01, -2.622629761934E+01,
                                0,                   0,                   0,                   0,
                                0,                   0,                   0,                   0,
                                0,                   0,                   0,                   0,
                                0,                   0,                   0,                   0,
                                0,                   0,                   0,                   0,
                                0,                   0,                   0,                   0,
                                0, -1.381551055796E+01, -1.004274961987E+01, -8.628124752124E+00,
              -8.571702176917E+00, -7.501527823569E+00, -6.912767820806E+00, -6.547217804229E+00,
              -6.334011195670E+00, -5.987233510580E+00, -5.708573935392E+00, -5.400837475539E+00,
              -5.179095366697E+00, -4.947914048204E+00, -4.814164314198E+00, -4.710019721108E+00,
              -4.643194015692E+00, -4.537511537514E+00, -4.455371820900E+00 ]

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertEqual( False, chunk.empty )
            self.assertEqual( 215, chunk.length )
            self.assertEqual( "ESZG", chunk.name )

            self.assertEqual( 215, len( chunk.xss_array ) )

            self.assertEqual( 43, chunk.NES )
            self.assertEqual( 43, chunk.number_energy_points )
            self.assertEqual( 43, len( chunk.energies ) )
            self.assertEqual( 43, len( chunk.incoherent ) )
            self.assertEqual( 43, len( chunk.coherent ) )
            self.assertEqual( 43, len( chunk.photoelectric ) )
            self.assertEqual( 43, len( chunk.pairproduction ) )

            self.assertAlmostEqual( -6.907755278982E+00, chunk.energies[0] )
            self.assertAlmostEqual(  4.605170185988E+00, chunk.energies[-1] )
            self.assertAlmostEqual( -2.474115088710E+00, chunk.incoherent[0] )
            self.assertAlmostEqual( -4.794460770140E+00, chunk.incoherent[-1] )
            self.assertAlmostEqual( -5.438809818403E-01, chunk.coherent[0] )
            self.assertAlmostEqual( -2.149558177385E+01, chunk.coherent[-1] )
            self.assertAlmostEqual(  2.449279472145E+00, chunk.photoelectric[0] )
            self.assertAlmostEqual( -2.622629761934E+01, chunk.photoelectric[-1] )
            self.assertAlmostEqual(  0.000000000000E+00, chunk.pairproduction[0] )
            self.assertAlmostEqual( -4.455371820900E+00, chunk.pairproduction[-1] )

            # verify the xss array
            xss = chunk.xss_array
            for index in range( chunk.length ) :

                self.assertAlmostEqual( self.chunk[index], xss[index] )

        # the data is given explicitly
        chunk = PhotoAtomicPrincipalCrossSectionBlock(
          energies =  [ -6.907755278982E+00, -6.502290170874E+00, -6.214608098422E+00, -5.809142990314E+00,
                        -5.521460917862E+00, -5.298317366548E+00, -5.115995809754E+00, -4.828313737302E+00,
                        -4.605170185988E+00, -4.199705077880E+00, -3.912023005428E+00, -3.506557897320E+00,
                        -3.218875824868E+00, -2.995732273554E+00, -2.813410716760E+00, -2.525728644308E+00,
                        -2.302585092994E+00, -1.897119984886E+00, -1.609437912434E+00, -1.203972804326E+00,
                        -9.162907318742E-01, -6.931471805600E-01, -5.108256237660E-01, -2.231435513142E-01,
                                          0,  2.176149178151E-02,  4.054651081082E-01,  6.931471805599E-01,
                         7.149086723415E-01,  1.098612288668E+00,  1.386294361120E+00,  1.609437912434E+00,
                         1.791759469228E+00,  2.079441541680E+00,  2.302585092994E+00,  2.708050201102E+00,
                         2.995732273554E+00,  3.401197381662E+00,  3.688879454114E+00,  3.912023005428E+00,
                         4.094344562222E+00,  4.382026634674E+00,  4.605170185988E+00 ],
          incoherent = [                                                                -2.474115088710E+00,
                         -1.801615884491E+00, -1.395274562701E+00, -9.619368437599E-01, -7.605035347293E-01,
                         -6.564816521895E-01, -5.973280393893E-01, -5.379604661733E-01, -5.121031060658E-01,
                         -4.951622704106E-01, -4.996615083952E-01, -5.236170868157E-01, -5.519549571767E-01,
                         -5.804883624210E-01, -6.082473646805E-01, -6.606006131276E-01, -7.087177755509E-01,
                         -8.132559185667E-01, -9.004223039898E-01, -1.039979295888E+00, -1.149677188087E+00,
                         -1.240439712683E+00, -1.318224582219E+00, -1.447723056117E+00, -1.554102548229E+00,
                         -1.565234595395E+00, -1.761517405317E+00, -1.920163458054E+00, -1.933037974696E+00,
                         -2.160044406212E+00, -2.341411164029E+00, -2.488070449328E+00, -2.611526212807E+00,
                         -2.812417876456E+00, -2.972959551555E+00, -3.273902395055E+00, -3.493770011977E+00,
                         -3.811227895393E+00, -4.041090092197E+00, -4.221732578372E+00, -4.370691125010E+00,
                         -4.608126551734E+00, -4.794460770140E+00 ],
          coherent = [                                           -5.438809818403E-01, -6.963824082700E-01,
                       -8.816695225475E-01, -1.286177569785E+00, -1.670840023917E+00, -2.009497655884E+00,
                       -2.303961039174E+00, -2.792755511835E+00, -3.189195670767E+00, -3.941353983624E+00,
                       -4.493199565291E+00, -5.286155621289E+00, -5.854953099262E+00, -6.298223430325E+00,
                       -6.661192120127E+00, -7.234899160315E+00, -7.680387322840E+00, -8.490556129031E+00,
                       -9.065634150977E+00, -9.876327742081E+00, -1.045166550264E+01, -1.089788037630E+01,
                       -1.126257928307E+01, -1.183793979483E+01, -1.228421366256E+01, -1.232773629793E+01,
                       -1.309513739115E+01, -1.367044098687E+01, -1.371396398204E+01, -1.448137141933E+01,
                       -1.505675956723E+01, -1.550303434392E+01, -1.586772611339E+01, -1.644309890848E+01,
                       -1.688938601110E+01, -1.770029298013E+01, -1.827562847225E+01, -1.908666032844E+01,
                       -1.966212006760E+01, -2.010848568546E+01, -2.047323890380E+01, -2.104887271593E+01,
                       -2.149558177385E+01 ],
          photoelectric = [                       2.449279472145E+00,  1.084175240870E+00,  1.079571415050E-01,
                            -1.277619344494E+00, -2.265289308250E+00, -3.033641846627E+00, -3.662432284099E+00,
                            -4.655516560425E+00, -5.426150738058E+00, -6.826175291990E+00, -7.816822165767E+00,
                            -9.208342369314E+00, -1.019143632722E+01, -1.094988696976E+01, -1.156738059480E+01,
                            -1.253596656679E+01, -1.328194544723E+01, -1.462406859004E+01, -1.556478541559E+01,
                            -1.687141755455E+01, -1.778410391488E+01, -1.848287534755E+01, -1.904747854397E+01,
                            -1.992620919300E+01, -2.059751463164E+01, -2.063568369061E+01, -2.130868929642E+01,
                            -2.181328515120E+01, -2.184419873302E+01, -2.238927410087E+01, -2.274935620313E+01,
                            -2.302861474576E+01, -2.323781965288E+01, -2.356790925614E+01, -2.382395870614E+01,
                            -2.424700380348E+01, -2.454714061185E+01, -2.497013240600E+01, -2.527026145888E+01,
                            -2.550312279898E+01, -2.569333036808E+01, -2.599348177338E+01, -2.622629761934E+01 ],
          pairproduction = [                   0,                   0,                   0,                   0,
                                               0,                   0,                   0,                   0,
                                               0,                   0,                   0,                   0,
                                               0,                   0,                   0,                   0,
                                               0,                   0,                   0,                   0,
                                               0,                   0,                   0,                   0,
                                               0, -1.381551055796E+01, -1.004274961987E+01, -8.628124752124E+00,
                             -8.571702176917E+00, -7.501527823569E+00, -6.912767820806E+00, -6.547217804229E+00,
                             -6.334011195670E+00, -5.987233510580E+00, -5.708573935392E+00, -5.400837475539E+00,
                             -5.179095366697E+00, -4.947914048204E+00, -4.814164314198E+00, -4.710019721108E+00,
                             -4.643194015692E+00, -4.537511537514E+00, -4.455371820900E+00 ] )

        verify_chunk( self, chunk )

if __name__ == '__main__' :

    unittest.main()
