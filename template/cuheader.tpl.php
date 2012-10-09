<div id="cu-header" class="clearfix <?php echo $cuheader_color_scheme; ?>">
  <div id="cu-logo">
    <h1 id="cu-site-name" style="background-image: url('<?php echo $cuheader_image_path; ?>'); width: <?php echo $cuheader_image_width; ?>px;"><?php echo l($cuheader_site_name, '<front>', array('attributes' => array('id' => array('cu-home-link')))); ?></h1>
  </div>
  <div id="cu-search-wrapper">
    <div id="cu-search">
      <div id="cu-links">
        CU: <a href="http://www.colorado.edu/">Home</a> &bull; <a href="http://www.colorado.edu/atoz">A to Z</a> &bull; <a href="http://www.colorado.edu/campusmap">Campus Map</a>
      </div>
      <div id="cu-search-form-wrapper" class="clearfix">
        <form id="cu-search-form">
          <div id="cu-search-input-wrapper">
          	<label for="cu-search-input">Enter search query</label>
            <input id="cu-search-input" type="text" value="Search this Site" onfocus="this.value=''" />
            <label for="cu-search-submit">Submit search</label>
            <input id="cu-search-submit" type="submit" value="Search" style="background-image: url('<?php echo $cuheader_submit_image_path; ?>')" />
          </div>
        </form>
      </div>
    </div>
  </div>
</div>