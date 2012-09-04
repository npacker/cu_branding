<div id="cu-footer" class="clearfix">
  <div id="cu-footer-info">
    <span id="cu-footer-name"><?php echo $cufooter_site_name; ?></span><br />
    <?php if (!empty($cufooter_address_1)) { ?>
    <span id="cu-footer-street"><?php echo $cufooter_address_1; ?></span><br /><?php } ?>
    <?php if (!empty($cufooter_address_2)) { ?>
    <span id="cu-footer-street"><?php echo $cufooter_address_2; ?></span><br /><?php } ?>
    <?php if (!empty($cufooter_zip)) { ?>
    <span id="cu-footer-city-zip">Boulder, CO <?php echo $cufooter_zip; ?></span><br /><?php } ?>
    <?php if (!empty($cufooter_phone)) { ?>
    <span id="cu-footer-phone"><?php echo $cufooter_phone; ?></span><br /><?php } ?>
    <?php if (!empty($cufooter_email)) { ?>
    <span id="cu-footer-email"><a href="mailto:<?php echo $cufooter_email; ?>"><?php echo $cufooter_email; ?></a></span><?php } ?>
  </div>
  <div id="cu-footer-branding-copyright">
    <a title="University of Colorado Boulder" target="_blank" href="http://www.colorado.edu/">University of Colorado Boulder</a><?php if (!empty($cufooter_login_link)) { ?> &bull; <span id="cu-footer-login-link"><?php echo l('Login', 'user'); ?></span><?php } ?><br />
    <a title="Legal & Trademarks" target="_blank" href="http://www.colorado.edu/about/legal.html">Legal &amp; Trademarks</a> &bull; <a title="Privacy" target="_blank" href="http://www.colorado.edu/privacy/">Privacy</a><br />
    <a title="Board of Regents" target="_blank" href="https://www.cu.edu/regents/"> &copy; <?php echo $cufooter_date; ?> Regents of the University of Colorado</a>
  </div>
  <div id="cu-footer-credits">
    Website designed by <a title="ASSETT" target="_blank" href="http://assett.colorado.edu">ASSETT</a>
  </div>
</div>